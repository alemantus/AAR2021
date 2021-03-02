function [ poseOut, covOut ] = positionPrediction( poseIn,covIn,delSr,delSl)
%[poseOut, covOut] = POSITIONPREDICTION(poseIn,covIn,delSr,delSl) perform
%one step of robot pose prediction from a set of wheel displacements
%   poseIn = old robot pose
%   covIn = uncertainty on the old robot pose
%   delSr = right wheel linear displacement
%   delSl = left wheel linear displacement


%% Constants
% The robot parameters are read globally, odoB is the wheel separation, kR
% and kL are the odometry uncertainty parameters
global odoB kR kL 
delS = (delSr+delSl)/2;
delT = (delSr-delSl)/odoB;
%% pose update
poseOut = poseIn + [delS*cos(poseIn(3)+delT/odoB); delS*sin(poseIn(3)+delT/odoB); delT];

%% Covariance update
                
covOut = zeros(3,3);

end
