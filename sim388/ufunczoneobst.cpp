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

#ifdef LIBRARY_OPEN_NEEDED

/**
 * This function is needed by the server to create a version of this plugin */
UFunctionBase * createFunc()
{ // create an object of this type
  /** replace 'UFunczoneobst' with your class name */
  return new UFunczoneobst();
}
#endif




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

void UFunczoneobst::pol2carth(double theta[501], double dist[501], double carth[][501]){

  for (int i=0; i<501; i++){
    carth[0][i] = dist[i]*cos(theta[i]);
    carth[1][i] = dist[i]*sin(theta[i]);
  }
  //return **carth;
}



void UFunczoneobst::transform(double carth[][501], double x, double y, double a){
  

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
  //
  int i,j,imax;
  double r[501];
  double delta;
  double minRange = 1000; // min range in meter
  for (j=0;j<=501;j++) r[j]=minRange;

  // double minAngle = 0.0; // degrees
//   double d,robotwidth;
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
      

      //Something in this fucks up the code
      

      theta[0] = M_PI/2;
      tmp = data->getRangeMeter(0);
      if (tmp >= 0.020)
        { // less than 20 units is a flag value for URG scanner
          if (tmp<r[0])
	     r[0]=tmp;
        }

      for(j = 1; j <= imax; j++){
	theta[j] = theta[j-1]-delta;
        tmp = data->getRangeMeter(j);

	if (tmp >= 0.020)
        { // less than 20 units is a flag value for URG scanner
          if (tmp<r[j])
	     r[j]=tmp;
        }

      }
	

	//Trying to fix the segmentation error

      double carthCoord[2][501], carthPoint[2][501];
      pol2carth(theta, r, carthCoord);
      //memcpy((void *)carthCoord, (void *)carthPoint, sizeof(carthPoint));

      snprintf(reply, MRL, "<carthCoord1=\"%g\" carthCoord2=\"%g\" theta=\"%f\" dist=\"%g\", scanmid=\"%f\"/>\n", carthCoord[0][450],carthCoord[1][450], theta[450],r[450], data->getRangeMeter(450));

      //send this string as the reply to the client

      /*snprintf(reply, MRL, "<laser l1=\"%g\" l1=\"%g\" l2=\"%g\" l3=\"%g\" l4=\"%g\" "
                                  "l5=\"%g\" l6=\"%g\" l7=\"%g\" l8=\"%g\" />\n", 
	                  zone[0],zone[1],zone[2],zone[3],zone[4],
                           zone[5],zone[6],zone[7],zone[8]);
      */

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















