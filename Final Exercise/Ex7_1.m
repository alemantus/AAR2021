close all; clear; clc;

%Defining line with start (3,-4) and end (3,1) 
lines(1,1) = 4;
lines(2,1) = -4;
lines(3,1) = 1;
lines(4,1) = 1;

lines(1,2) = 1;
lines(2,2) = 1;
lines(3,2) = 1.5;
lines(4,2) = 4;


%Scanner pose
x = 0;
y = 0;
theta = 0;

%Other input
maxDistance = 4;
resol = 0.36;
field_of_view = 180;

%Calling laserscanner
pol = laserscanHighresol(x, y, theta, lines, maxDistance, resol, field_of_view);

%Converting to cartesian
carth = polar2carth(pol);

[poseW] = transform(carth, x, y, theta);

figure
polarplot(pol(1,:),pol(2,:))

figure
plot(carth(1,:),carth(2,:))
line([lines(1,1) lines(3,1)], [lines(2,1) lines(4,1)],'Color','red','LineStyle','--')


%figure
%polarplot(pol(1,:),pol(2,:))


