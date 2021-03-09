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

%Number of matched lines
N = sum(matchResult(5,:));

%Find the matches:
for i = 1:length(matchResult(1,:))
    if matchResult(5,i) == 1
        %All the lines that have a match will come out here
    end
    
end


%poseOut = poseIn + K_t*v_t
%poseCovOut = poseCovIn - K_t*sigma_IN*transpose(K_t)
%K_t = poseCovIn*transpose(H_t)*inv(sigma_IN)

%We have to find:
%v_t(innovation = measured - predicted)
%sigma_IN (innovation covariance)
%H_t (jacobi of h_i(worldLines, pose, lsrRelPose)


%Can be simplified to:
%poseOut = poseIn + poseCovIn*inv(poseCovIn+R_t)*(z_t-poseIn)
%poseCovOut = poseCovIn - poseCovIn*inv(poseCovIn+R_t)*poseCovIn

%We have to find R_t, z_t

    
poseOut = poseIn;
poseCovOut = poseCovIn;

end
