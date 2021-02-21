function [newpose,tVec] = kinstep(pose, robotpar, ts, runningTime, wheelspeed)




%Function that calculates the pose based on robot parameters 


% Initialize time, input, and pose arrays
tVec = 0:ts:runningTime; % Time array

%Robot parameters
w = robotpar(1);
rR = robotpar(2);
rL = robotpar(3);

RSpeed = wheelspeed(1);
LSpeed = wheelspeed(2);

%Simulate once

%Definding theta and calculate new rotation matrix for each step
theta = pose(3);
R = [cos(theta) sin(theta) 0; -sin(theta) cos(theta) 0; 0 0 1];
    
% R\Matrix is the same as inv(R)*matrix
xi_dot = inv(R)*[0.5 0.5 0; 0 0 1; 1/w -1/w 0]*[rR*RSpeed; rL*LSpeed; 0];



% %New pose = old pose + xi_dot*sampleTime
temppose = pose' + xi_dot*ts;


newpose=temppose;
%display("newpose"+newpose(end,:))

end

