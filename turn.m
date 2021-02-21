function [pose,time] = turn(pose, turnAngle, rotationSpeed, robotpar, ts)

%Robot parameters
w = robotpar(1);
rR = robotpar(2);
rL = robotpar(3);



if turnAngle > 0
%Setting wheelspeed for turning around center
    wheelspeed(1) = (rotationSpeed*w)/rR;
    wheelspeed(2) = (-rotationSpeed*w)/rL;
else
    wheelspeed(1) = (-rotationSpeed*w)/rR;
    wheelspeed(2) = (rotationSpeed*w)/rL;
end
%Getting runningTime from turnAngle and rotationSpeed
runningTime = abs(turnAngle) / (2*rotationSpeed);

[pose, time] = kinupdate(pose, robotpar, ts, runningTime, wheelspeed);
end

