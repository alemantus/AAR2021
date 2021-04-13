/***************************************************************************
 *   Copyright (C) 2005 by Christian Andersen and DTU                      *
 *   jca@oersted.dtu.dk                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "ufunczoneobst.h"
#include <cmath>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <utils/localizationutils.h>
using namespace cv;

#ifdef LIBRARY_OPEN_NEEDED

/**
 * This function is needed by the server to create a version of this plugin */
UFunctionBase * createFunc()
{ // create an object of this type
  /** replace 'UFunczoneobst' with your class name */
  return new UFunczoneobst();
}
#endif

double boxWidth;


bool UFunczoneobst::setResource(UResBase * resource, bool remove) { // load resource as provided by the server (or other plugins)
	bool result = true;

	if (resource->isA(UResPoseHist::getOdoPoseID())) { // pointer to server the resource that this plugin can provide too
		// but as there might be more plugins that can provide the same resource
		// use the provided
		if (remove)
			// the resource is unloaded, so reference must be removed
			poseHist = NULL;
		else if (poseHist != (UResPoseHist *) resource)
			// resource is new or is moved, save the new reference
			poseHist = (UResPoseHist *) resource;
		else
			// reference is not used
			result = false;
	}

	// other resource types may be needed by base function.
	result = UFunctionBase::setResource(resource, remove);
	return result;
}

//transform polar coordinates to cartessian
void UFunczoneobst::pol2carth(double* theta, double* dist, double carth[][501]){
  const int MRL = 500;
  char reply[MRL];

  for (int i=0; i<501; i++){
    carth[0][i] = dist[i]*cos(theta[i]);
    carth[1][i] = dist[i]*sin(theta[i]);
    snprintf(reply, MRL, "carthX=\"%g\" carthY=\"%g\" dist=\"%g\" i=\"%d\" />\n",
                  carth[0][i], carth[1][i], dist[i], i);

    sendMsg(msg, reply);
  }
  //return **carth;
}

//transform from local to global?
void UFunczoneobst::transform(double carth[][501], double x, double y, double a, double poseW[][501]){

  for (int i=0; i<501; i++){
    poseW[0][i] = cos(a)*carth[0][i]-sin(a)*carth[1][i]+x;
    poseW[1][i] = sin(a)*carth[0][i]+cos(a)*carth[1][i]+y;
    poseW[2][i] = a + atan2(carth[1][i], carth[0][i]);
  }
}

//matrix dotProduct
double UFunczoneobst::dotProduct(double* x, double* y, int lengthX){
   double product = 0;
   for (int i = 0; i < lengthX; i++){
     product = product + x[i] * y[i];



   }
   
    const int MRL = 500;
    char reply[MRL];
    snprintf(reply, MRL, "<product=\"%g\" />\n",
                    product);
  

  sendMsg(msg, reply);


   return product;
}

//lsqline find the distance to an object and the angle of a line
//perpendicular to the object
void UFunczoneobst::lsqline(double* x, double* y, double* line, int lengthX){
  double x_sum;
  double y_sum;

  //Get mean of the two arrays
  const int MRL = 500;
  char reply[MRL];


  for (int i = 0; i < lengthX; i++){
    x_sum += x[i];
    y_sum += y[i];
  }	

  snprintf(reply, MRL, "<lengthX=\"%d\" />\n",
                    lengthX);
  

  sendMsg(msg, reply);
  


  double x_mean = x_sum/lengthX;
  double y_mean = y_sum/lengthX;

  double num = 2*x_sum*y_sum-2*lengthX*dotProduct(x, y, lengthX);
  double den = x_sum*x_sum-y_sum*y_sum-lengthX*dotProduct(x, x, lengthX)+lengthX*dotProduct(y, y, lengthX);
  line[0] = atan2(num, den)/2;

  line[1] = x_mean*cos(line[0])+y_mean*sin(line[0]);

  if (line[1] < 0){
    line[1] = -line[1];

    if(line[0] < 0){
      line[0] += M_PI;

    }else{
      line[0] -= M_PI;
    }
  }

}

//finds the startIndex, endIndex and cornerindex
void UFunczoneobst::squareDetect(double theta[501], double dist[501], double poseW[][501], int minRange, double* square, double* lsqlines){

  const int MRL = 500;
  char reply[MRL];

  int startIndex = 0;
  int endIndex = 0;
  double filterOut[501];
  Point anchor = Point( -1, -1 );
  double delta = 0;
  int ddepth = -1;
  double line1[2], line2[2];
  double distDiff[501];
  int const nf = 501;
  int const ng = 25;
  int n = 25+501 -1;

  //Gaussian kernel
  static const double kernel[25] = { 0.0029690167439504968, 0.013306209891013651,
    0.021938231279714643, 0.013306209891013651, 0.0029690167439504968,
    0.013306209891013651, 0.059634295436180138, 0.098320331348845769,
    0.059634295436180138, 0.013306209891013651, 0.021938231279714643,
    0.098320331348845769, 0.16210282163712664, 0.098320331348845769,
    0.021938231279714643, 0.013306209891013651, 0.059634295436180138,
    0.098320331348845769, 0.059634295436180138, 0.013306209891013651,
    0.0029690167439504968, 0.013306209891013651, 0.021938231279714643,
    0.013306209891013651, 0.0029690167439504968 };


  //find startIndex and endIndex
  for (int i=0; i<501; i++){
    if (dist[i] < minRange){
      startIndex = i;
      break;
    }
  }

  for (int i=500; i>=startIndex; i--){
    if (dist[i] < minRange){
      endIndex = i;
      break;
    }
  }

  //Smoothing using Gaussian filter
  if (endIndex != 0){


          //outcommenting the gaussian filter (maybe just reduce the kernel?

	  for(auto i(0); i < n; ++i) {
	    int const jmn = (i >= ng - 1)? i - (ng - 1) : 0;
	    int const jmx = (i <  nf - 1)? i            : nf - 1;
	    for(auto j(jmn); j < jmx; ++j) {
	      filterOut[i] += (dist[j] * kernel[i - j]);
	    }
	  }

	  //Take the derivative twice:
	  int cornerIndex = startIndex+1;
	  for (int i = startIndex; i <= endIndex; i++){
	    
	    //distDiff[i] = filterOut[i];
	    distDiff[i] = dist[i];
      //## ?? ##
	    if (i < 2){
	      distDiff[i] = 0;
	    }
      //## ?? ##
	    //distDiff[i] = filterOut[i]-filterOut[i-1]-filterOut[i-2];
	    distDiff[i] = dist[i]-dist[i-1]-dist[i-2];

	    //Find index for max value
	    if(distDiff[i] > distDiff[cornerIndex]){
	      cornerIndex = i;
	    }
      double maxVal = distDiff[cornerIndex];


      snprintf(reply, MRL, "<cornerIndex=\"%d\" startIndex=\"%d\" distDiff=\"%g\" endIndex=\"%d\" maxVal=\"%g\" index=\"%d\" />\n",
                    cornerIndex, startIndex, distDiff[i], endIndex, maxVal, i);

      sendMsg(msg, reply);

	  }


	  //Make point clouds for both lines
	  double x1[cornerIndex-startIndex], y1[cornerIndex-startIndex];
	  double x2[endIndex-cornerIndex], y2[endIndex-cornerIndex];



    for (int i = startIndex; i <= cornerIndex; i++){
	    x1[i - (startIndex)]=poseW[0][i];
	    y1[i - (startIndex)]=poseW[1][i];
      snprintf(reply, MRL, "<i=\"%d\" x1=\"%g\" y1=\"%g\" />\n",
                    i, poseW[0][i], poseW[1][i]);

      sendMsg(msg, reply);

	  }

	  for (int i = cornerIndex; i <= endIndex; i++){
	    x2[i - (cornerIndex)]=poseW[0][i];
	    y2[i - (cornerIndex)]=poseW[1][i];
      	    snprintf(reply, MRL, "<i=\"%d\" x2=\"%g\" y2=\"%g\" />\n",
                    i, poseW[0][i], poseW[1][i]);

      	    sendMsg(msg, reply);
		//snprintf(reply, MRL, "<startindex=\"%d\" endindex=\"%d\" cornerIndex=\"%d\", itertation=\"%d\"/>\n", startIndex, endIndex, cornerIndex, i);
  	  	//sendMsg(msg, reply);
	  }



	  //Not to be confused with the length of the sides, this is just the array sizes
	  int lengthX= sizeof(x1)/sizeof(x1[0]);



	  //Find lines with lsqline

	  lsqline(x1, y1, line1, lengthX);

	  lengthX= sizeof(x2)/sizeof(x2[0]);

	
	  lsqline(x2, y2, line2, lengthX);
	  lsqlines[0] = line1[0];
	  lsqlines[1] = line2[0];

	  lsqlines[2] = line1[1];
	  lsqlines[3] = line2[1];

    	  //length of the found object lines
	  double length1 = sqrt( pow( (poseW[0][startIndex]-poseW[0][cornerIndex]) ,2) + pow( (poseW[1][startIndex]-poseW[1][cornerIndex]), 2) );
	  double length2 = sqrt( pow( (poseW[0][endIndex]-poseW[0][cornerIndex]) ,2) + pow( (poseW[1][endIndex]-poseW[1][cornerIndex]), 2) );

	  lsqlines[4] = length1;
	  lsqlines[5] = length2;

    	  //Determine the orientation of the object
	  if (length1 > length2){
	    square[2] = line2[0];
	    boxWidth = length2;
	  }else{
	    square[2] = line1[0];
	    boxWidth = length1;
	  }
	  square[0] = (poseW[0][startIndex]+poseW[0][endIndex])/2;
	  square[1] = (poseW[1][endIndex]+poseW[1][startIndex])/2;
  }
}

void UFunczoneobst::parking(double* square, double* parkingCoordinate)
{


	//Displace square center to make a parking spot:

	double dx, dy;
	double displace = 0.2+0.26+boxWidth/2;
	if(square[2] > M_PI/2){ //short side close over robot
		dx = displace*sin(square[2] - M_PI/2);
		dy = -displace*cos(square[2] - M_PI/2);
	}else if((square[2] < M_PI/2) && (square[2] > 0)){ //long side close over robot
		dx = -displace*cos(square[2]);
		dy = -displace*sin(square[2]);
	}else if((square[2] < 0) && (square[2] >-M_PI/2)){ //long side close under robot
		dx = -displace*cos(square[2]);
		dy = -displace*sin(square[2]);
	}else if(square[2] > -M_PI/2){ //short side close under robot
		dx = displace*sin(square[2] - M_PI/2);
		dy = displace*cos(square[2] - M_PI/2);
	}
	parkingCoordinate[0]=square[0]+dx;
	parkingCoordinate[1]=square[1]+dy;

}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
// #define SMRWIDTH 0.4
bool UFunczoneobst::handleCommand(UServerInMsg * msg, void * extra)
{  // handle a plugin command


  //These defines are OK
  double theta[501];
  double poseW[3][501];
  double carthCoord[2][501], carthPoint[2][501];
  double square[3];
  double lsqlines[6];
  double parkingCoordinate[3];
  //Apparently defining an array like this: double* theta[501]{} - doesnt work. It results in the segmentation fault


  const int MRL = 500;
  char reply[MRL];
  bool ask4help;
  const int MVL = 30;
  char value[MVL];
  ULaserData * data;
  double robotwidth;
  double x;
  double y;
  double alpha;
  double tmp;
  double angleRelation;
  //
  int i,j,imax;
  double r[501];
  double delta;
  double minRange = 10; // min range in meter
  for (j=0;j<501;j++) r[j]=minRange;

  double zone[9];
  // check for parameters - one parameter is tested for - 'help'
  ask4help = msg->tag.getAttValue("help", value, MVL);
  if (ask4help)
  { // create the reply in XML-like (html - like) format
    sendHelpStart(msg, "zoneobst");
    sendText("--- available zoneobst options\n");
    sendText("help            This message\n");
    sendText("fake=F          Fake some data 1=random, 2-4 a fake corridor\n");
    sendText("device=N        Laser device to use (see: SCANGET help)\n");
    sendText("see also: SCANGET and SCANSET\n");
    sendHelpDone();
  }
  else
  { // do some action and send a reply
    data = getScan(msg, (ULaserData*)extra);
    //
    if (data->isValid())
    {
    // check if a attribute (parameter) with name width exists and if so get its value
       bool gotwidth = msg->tag.getAttValue("width", value, MVL);
       if (gotwidth) {
        	robotwidth=strtod(value, NULL);
       }
       else {
        	robotwidth=0.26;
      }
      UPose poseAtScan = poseHist->getPoseAtTime(data->getScanTime());
      x = poseAtScan.x;
      y = poseAtScan.y;
      alpha = poseAtScan.h;
      // Gets the odometry pose at the time when the laserscan was taken, poseAtScan.x poseAtScan.y poseAtScan.a (x,y,angle)
      // make analysis for closest measurement
      imax = data->getRangeCnt();

      delta = M_PI/imax;



      theta[0] = M_PI/2;
      tmp = data->getRangeMeter(0);
      if (tmp >= 0.020)
        { // less than 20 units is a flag value for URG scanner
          if (tmp<r[0])
	     r[0]=tmp;
        }

      for(j = 1; j < imax; j++){
	theta[j] = theta[j-1]-delta;
        tmp = data->getRangeMeter(j);

	if (tmp >= 0.020)
        { // less than 20 units is a flag value for URG scanner
          if (tmp<r[j])
	     r[j]=tmp;
        }
      }
      pol2carth(theta, r, carthCoord);

      squareDetect(theta, r, carthCoord, minRange, square, lsqlines);
      //squareDetect(theta, r, carthCoord, minRange, square, lsqlines);
      //squareDetect(theta, r, carthCoord, minRange, square, lsqlines);

      angleRelation = abs(lsqlines[1]-lsqlines[0]);



      parking(square,parkingCoordinate);

      snprintf(reply, MRL, "<laser l1=\"%g\" l2=\"%g\" l3=\"%g\" \n parkX=\"%g\" parkY=\"%g\" corner angle=\"%g\" Angle line1=\"%g\" Angle line2=\"%g\" distance to line1=\"%g\" distance to line2=\"%g\" lengthLine1=\"%g\" lengthline2 =\"%g\"  />\n",
	                  square[0],square[1],square[2],parkingCoordinate[0],parkingCoordinate[1],angleRelation,lsqlines[0],lsqlines[1],lsqlines[2],lsqlines[3],lsqlines[4],lsqlines[5]);

      sendMsg(msg, reply);
    }
    else
      sendWarning(msg, "No scandata available");
  }
  // return true if the function is handled with a positive result
  // used if scanpush or push has a count of positive results
  return true;
}

void UFunczoneobst::createBaseVar()
{ // add also a global variable (global on laser scanner server) with latest data
  var_zone = addVarA("zone", "0 0 0 0 0 0 0 0 0", "d", "Value of each laser zone. Updated by zoneobst.");
}