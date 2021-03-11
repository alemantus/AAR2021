function [ poseOut, poseCovOut ] = measurementUpdate( poseIn, poseCovIn, matchResult)
%[ poseOut, poseCovOut ] =MEASUREMENTUPDATE ( poseIn, poseCovIn,
%matchResult ) perform extended Kalman filter measurement update on the
%estimated robot pose poseIn with covariance poseCovIn using a set of
%matched predicted and extracted laser scanner lines given in matchResult.
%The arguments are defined as:
%       poseIn: The estimated robot pose given as [x,y,theta]
%       poseCovIn: The estimated covariance matrix of the robot pose
%       matchResult: A (5xnoOfWorldLines) matrix whose columns are 
%       individual pairs of line matches. It is structured as follows:
%       matchResult = [ worldLine(1,1) , worldLine(1,2) ...  ]
%                     [ worldLine(2,1) , worldLine(2,2)      ]
%                     [ innovation1(1) , innovation2(1)      ]
%                     [ innovation1(2) , innovation2(2)      ]
%                     [ matchIndex1    , matchIndex2    ...  ]
%           Note that the worldLines are in the world coordinates!
%       
%       poseOut: The updated robot pose estimate
%       poseCovOut: The updated estimate of the robot pose covariance 
%       matrix 

% Constants
% The laser scanner pose in the robot frame is read globally(lsrRelpose)
% The varAlpha and varR are the assumed variances of the parameters of
% the extracted lines, they are also read globally
global lsrRelPose varAlpha varR

sigmaR = [varAlpha 0; 0 varR];

%Number of matched lines
%N = sum(matchResult(5,:));

%Find the matches:
for i = 1:length(matchResult(1,:))
    if matchResult(5,i) == 1
        %All the lines that have a match will come out here
        zw(1) = matchResult(3,i);
        zw(2) = matchResult(3,i);
        v_t(1) = matchResult(3,i);
        v_t(2) = matchResult(4,i);
    end
    
end


if sum(matchResult(5,:)) >= 1
H = [0 0 -1; -cos(zw(1)) -sin(zw(1)) lsrRelPose(1)*sin(-zw(1)+poseIn(3))+lsrRelPose(2)*cos(-zw(1)+poseIn(3))];
sigma_IN = H*poseCovIn*transpose(H)+sigmaR;
K_t = poseCovIn*transpose(H)*inv(sigma_IN);


poseOut = poseIn + K_t*transpose(v_t);
poseCovOut = poseCovIn - K_t*sigma_IN*transpose(K_t);

%K_t = poseCovIn*transpose(H_t)*inv(sigma_IN)

%We have to find:
%v_t(innovation = measured - predicted)
%sigma_IN (innovation covariance)
%H_t (jacobi of h_i(worldLines, pose, lsrRelPose)
disp ("POSITION CORRECTED!")
else
    
poseOut = poseIn;
poseCovOut = poseCovIn;
end
end
