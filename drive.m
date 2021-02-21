function [pose,time] = drive(pose, drivenDist, speed, robotpar, ts)


%Robot parameters
w = robotpar(1);
rR = robotpar(2);
rL = robotpar(3);

%Calculating angular speed for linear speed
wheelspeed(1) = speed / rR;
wheelspeed(2) = speed / rL;

%Getting runningTime from drivenDist
runningTime = drivenDist / speed;

[pose, time] = kinupdate(pose, robotpar, ts, runningTime, wheelspeed);



end

