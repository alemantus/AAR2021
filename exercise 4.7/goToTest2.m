clear all; close all; clc;

poseInit = [0 0 0];
targetPose = [0.5 0.5 -pi];
robotpar = [0.26 0.035 0.035];
ts = 0.01;
drivenDist = 10;
speed = 0.5;

turnAngleDegree = 90;
turnAngle = turnAngleDegree*pi / 180;
rotationSpeed = 0.1; %rad/s

%[pose, time] = linedrive([0 0 0], poseInit, robotpar, ts);
[pose2, time2] = linedrive([0.5 0 0], poseInit, robotpar, ts);
[pose3, time3] = linedrive([0.5 0.5 0],poseInit, robotpar, ts);
[pose4, time4] = linedrive([0.5 -0.5 -pi/2], poseInit, robotpar, ts);
[pose5, time5] = linedrive([0 0.5 -pi], poseInit, robotpar, ts);
[pose6, time6] = linedrive( [0 0 pi/2],poseInit, robotpar, ts);
[pose7, time7] = linedrive( [0 -0.5 0],poseInit, robotpar, ts);
[pose8, time8] = linedrive( [-0.5 0.5 0], poseInit,robotpar, ts);
[pose9, time9] = linedrive([-0.5 0 0], poseInit, robotpar, ts);
[pose10, time10] = linedrive( [-0.5 -0.5 -pi],poseInit, robotpar, ts);

figure 
% pose4;
% poseFinal = [pose pose2 pose3];



hold on
plot(pose2(:,1),pose2(:,2),'--');

hold on
plot(pose3(:,1),pose3(:,2),'--');

hold on 
plot(pose4(:,1),pose4(:,2),'--');

hold on
plot(pose5(:,1),pose5(:,2),'--');

hold on
plot(pose6(:,1),pose6(:,2),'--');

hold on 
plot(pose7(:,1),pose7(:,2),'--');

hold on 
plot(pose8(:,1),pose8(:,2),'--');

hold on 
plot(pose9(:,1),pose9(:,2),'--');

hold on 
plot(pose10(:,1),pose10(:,2),'--');


xlim([-0.6 0.6])

ylim([-0.6 0.6])
legend('pose1','pose2', 'pose3', 'pose4','pose5','pose6', 'pose7', 'pose8','pose9')


ylabel('y-direction [m]')
xlabel('x-direction [m]')

hold off

display("pose 1 " + pose2(end,:))
display("pose 2 " + pose3(end,:))
display("pose 3 " + pose3(end,:))
display("pose 4 " + pose4(end,:))
display("pose 5 " + pose5(end,:))
display("pose 6 " + pose6(end,:))
display("pose 7 " + pose7(end,:))
display("pose 8 " + pose8(end,:))
display("pose 9 " + pose9(end,:))
display("pose 10 " + pose10(end,:))


