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
%Taken from eq 5.89
poseOut = poseIn + [delS*cos(poseIn(3)+delT/odoB); delS*sin(poseIn(3)+delT/odoB); delT];

%% Covariance update
Qt = [kR*abs(delSr) 0; 0 kL*abs(delSl)];
Fx = [1 0 -delT*sin(poseIn(3)+delT/2); 0 1 delT*cos(poseIn(3)+delT/2); 0 0 1];

Fu = zeros(3,2);
Fu(1,1) = 0.5*cos(poseIn(3)+delT/2)-(delS/2*odoB)*sin(poseIn(3)+delT/2);
Fu(1,2) = 0.5*cos(poseIn(3)+delT/2)+(delS/2*odoB)*sin(poseIn(3)+delT/2);
Fu(2,1) = 0.5*sin(poseIn(3)+delT/2)+(delS/2*odoB)*cos(poseIn(3)+delT/2);
Fu(2,2) = 0.5*sin(poseIn(3)+delT/2)-(delS/2*odoB)*cos(poseIn(3)+delT/2);
Fu(3,1) = 1/odoB;
Fu(3,2) = -1/odoB;

covOut = Fx*covIn*transpose(Fx)+Fu*Qt*transpose(Fu);
%covOut = zeros(3,3);

end
