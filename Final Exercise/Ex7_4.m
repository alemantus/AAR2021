close all; clear; clc;

%Line enviroment
%Line 1
lines(1,1) = 0;
lines(2,1) = 1;
lines(3,1) = 2.5;
lines(4,1) = 1;

%Line 2
lines(1,2) = 2.5;
lines(2,2) = 1;
lines(3,2) = 2.5;
lines(4,2) = 5;

%Line 3
lines(1,3) = 0;
lines(2,3) = -1;
lines(3,3) = 3.5;
lines(4,4) = -1;

%Line 4
lines(1,4) = 3.5;
lines(2,4) = -1;
lines(3,4) = 3.5;
lines(4,4) = 5;


%Laser pose
x1 = 0; x2 = 1.0; x3 = 1.5;
y1 = 0; y2 = 0; y3 = 0;
theta1 = 0; theta2 = 0; theta3 = pi/6;

%Other input
maxDistance = 4;
resol = 0.36;
field_of_view = 180;

%Calling laserscanner
pol1 = laserscanHighresol(x1, y1, theta1, lines, maxDistance, resol, field_of_view);
pol2 = laserscanHighresol(x2, y2, theta2, lines, maxDistance, resol, field_of_view);
pol3 = laserscanHighresol(x3, y3, theta3, lines, maxDistance, resol, field_of_view);

%Converting to cartesian
carth1 = polar2carth(pol1);
carth2 = polar2carth(pol2);
carth3 = polar2carth(pol3);

%Converting from laser pose to world pose
poseW1 = transform(carth1, x1, y1, theta1);
poseW2 = transform(carth2, x2, y2, theta2);
poseW3 = transform(carth3, x3, y3, theta3);


%Plot of lines from world pose
figure
hold on
plot(poseW1(1,:), poseW1(2,:))
plot(poseW2(1,:), poseW2(2,:))
plot(poseW3(1,:), poseW3(2,:))
line([lines(1,1) lines(3,1)],[lines(2,1) lines(4,1)],'linestyle','--','Color','green');
line([lines(1,2) lines(3,2)],[lines(2,2) lines(4,2)],'linestyle','--','Color','green');
line([lines(1,3) lines(3,3)],[lines(2,3) lines(4,3)],'linestyle','--','Color','green');
line([lines(1,4) lines(3,4)],[lines(2,4) lines(4,4)],'linestyle','--','Color','green');
hold off
title("Plot of world pose")
legend("(0,0,0)","(1.0,0,0)","(1.5,0,pi/6)","Wall")
xlim([-1 5])
ylim([-3 4.5])

%Plot of lines from laser pose
figure
hold on
plot(carth1(1,:), carth1(2,:))
plot(carth2(1,:), carth2(2,:))
plot(carth3(1,:), carth3(2,:))
line([lines(1,1) lines(3,1)],[lines(2,1) lines(4,1)],'linestyle','--','Color','green');
line([lines(1,2) lines(3,2)],[lines(2,2) lines(4,2)],'linestyle','--','Color','green');
line([lines(1,3) lines(3,3)],[lines(2,3) lines(4,3)],'linestyle','--','Color','green');
line([lines(1,4) lines(3,4)],[lines(2,4) lines(4,4)],'linestyle','--','Color','green');
hold off
title("Plot of laser pose")
legend("(0,0,0)","(1.0,0,0)","(1.5,0,pi/6)","Wall")
xlim([-1 5])
ylim([-3 4.5])




