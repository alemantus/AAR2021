close all; clear; clc;

%Line enviroment
%Line 1 (x=5)
lines(1,1) = 5;
lines(2,1) = -8;
lines(3,1) = 5;
lines(4,1) = 3;

% %Line 2 (y=3)
% lines(1,2) = -6;
% lines(2,2) = 3;
% lines(3,2) = 5;
% lines(4,2) = 3;
% 
%Line 3 (y=-x-3)
%lines(1,3) = -6;
%lines(2,3) = 3;
%lines(3,3) = 5;
%lines(4,3) = -8;

%Laser pose
x = 0;
y = 0;
theta = 0;

%Other input
maxDistance = 6;
resol = 0.36;
field_of_view = 180;

%Calling laserscanner
pol = laserscanHighresol(x, y, theta, lines, maxDistance, resol, field_of_view);

%Converting to cartesian
carth = polar2carth(pol);

%Converting to world pose
poseW = transform(carth, x, y, theta);

%Defining lines
points(1,:) =  linspace(5,5,500);
points(2,:) = linspace(-8,3,500);


%Estemating lines
lineSee = lsqline(points);


%Plot of lines from world pose
figure
hold on
plot(poseW(1,:), poseW(2,:))
line([lines(1,1) lines(3,1)],[lines(2,1) lines(4,1)],'linestyle','--','Color','green');
%line([lines(1,2) lines(3,2)],[lines(2,2) lines(4,2)],'linestyle','--','Color','green');
%line([lines(1,3) lines(3,3)],[lines(2,3) lines(4,3)],'linestyle','--','Color','green');
hold off
title("Plot of world pose")
legend("(0,0,0)","Wall")
xlim([-10 10])
ylim([-10 5])