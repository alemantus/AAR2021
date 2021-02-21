clear all; close all; clc;

pose = [0 0 0];
robotpar = [0.26 0.035 0.035];
ts = 0.01;
runningTime = 2;
wheelspeed = [2.86 -2.86];


[pose, time] = kinupdate(pose, robotpar, ts, runningTime, wheelspeed);

figure 
plot(pose(1,:),pose(2,:))
title("Plot of robot motion")
xlabel("x-direction [m]")
ylabel("y-direction [m]")


figure
plot(time, pose(3,:)*180/pi)
title("Plot of robot angle over time")
xlabel("Time [s]")
ylabel("Theta [degree]")



    
