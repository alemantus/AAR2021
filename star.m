clear all; close all; clc;

poseInit = [0 0 0];
robotpar = [0.26 0.035 0.035];
ts = 0.01;
drivenDist = 10;
speed = 0.5;

turnAngleDegree = 144;
turnAngle = turnAngleDegree*pi / 180;
rotationSpeed = 0.1; %rad/s

%State program (star)
[pose, time] = drive(poseInit, drivenDist, speed, robotpar, ts);
[pose2, time2] = turn(pose(:,end), turnAngle, rotationSpeed, robotpar, ts);
[pose3, time3] = drive(pose2(:,end), drivenDist, speed, robotpar, ts);
[pose4, time4] = turn(pose3(:,end), turnAngle, rotationSpeed, robotpar, ts);
[pose5, time5] = drive(pose4(:,end), drivenDist, speed, robotpar, ts);
[pose6, time6] = turn(pose5(:,end), turnAngle, rotationSpeed, robotpar, ts);
[pose7, time7] = drive(pose6(:,end), drivenDist, speed, robotpar, ts);
[pose8, time8] = turn(pose7(:,end), turnAngle, rotationSpeed, robotpar, ts);
[pose9, time9] = drive(pose8(:,end), drivenDist, speed, robotpar, ts);
[pose10, time10] = turn(pose9(:,end), turnAngle, rotationSpeed, robotpar, ts);


%Array for full path
poseFinal = [pose pose2 pose3 pose4 pose5 pose6 pose7 pose8 pose9 pose10];
timeFinal = [time time2 time3 time4 time5 time6 time8 time9 time10];



figure 
plot(poseFinal(1,:),poseFinal(2,:))
title("Plot of robot motion")
xlabel("x-direction [m]")
ylabel("y-direction [m]")
xlim([-5 15])
ylim([-5 15])



    
