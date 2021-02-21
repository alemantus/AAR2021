function [newpose,tVec] = kinupdate(pose, robotpar, ts, runningTime, wheelspeed)
%Function that calculates the pose based on robot parameters 


% Initialize time, input, and pose arrays
tVec = 0:ts:runningTime; % Time array
newpose = zeros(3,numel(tVec)); % Pose matrix
newpose(:,1) = pose(:,1);

%Robot parameters
w = robotpar(1);
rR = robotpar(2);
rL = robotpar(3);

RSpeed = wheelspeed(1);
LSpeed = wheelspeed(2);

%Simulation loop
for i = 2:numel(tVec) 
    
    %Definding theta and calculate new rotation matrix for each step
    theta = newpose(3,i-1);
    R = [cos(theta) sin(theta) 0; -sin(theta) cos(theta) 0; 0 0 1];
    
    % R\Matrix is the same as inv(R)*matrix
    xi_dot = R\[0.5 0.5 0; 0 0 1; 1/w -1/w 0]*[rR*RSpeed; rL*LSpeed; 0];
    
    % %New pose = old pose + xi_dot*sampleTime
    newpose(:,i) = newpose(:,i-1) + xi_dot*ts;         
end

end

