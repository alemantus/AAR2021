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
lines(4,3) = -1;

%Line 4
lines(1,4) = 3.5;
lines(2,4) = -1;
lines(3,4) = 3.5;
lines(4,4) = 5;


%Laser pose
x = 1.5;
y = 0;
theta = pi/6;

%Other input
maxDistance = 4;
resol = 0.36;
field_of_view = 180;

%Calling laserscanner
pol = laserscanHighresol(x, y, theta, lines, maxDistance, resol, field_of_view);


%Converting to cartesian
carth = polar2carth(pol);


%Converting from laser pose to world pose
poseW = transform(carth, x, y, theta);

%Defining lines 1
points1(1,:) =  linspace(0,1.36241,500);
%points1(1,:) =  linspace(0,0.368115,500);
points1(2,:) = linspace(1.1547,0.368115,500);

%Defining lines 2
points2(1,:) =  linspace(2.72371,1.20851,500);
points2(2,:) = linspace(0.717601,-1.85243,500);

%Defining lines 3
points3(1,:) =  linspace(1.20851,0,500);
%points3(1,:) =  linspace(1.20851,-1.85243,500);
points3(2,:) = linspace(-1.85243,-1.1547,500);

% %Defining lines 4
% points4(1,:) =  linspace(3.5,3.5,500);
% points4(2,:) = linspace(-1,5,500);



%Estemating lines 
lineSee = lsqline(points1);
lineSee2 = lsqline(points2);
lineSee3 = lsqline(points3);

%Task 7_8    
Alpha_w = lineSee(1)-theta;




figure
plot(carth(1,:),carth(2,:))
line([lines(1,1) lines(3,1)],[lines(2,1) lines(4,1)],'linestyle','--','Color','green');
line([lines(1,2) lines(3,2)],[lines(2,2) lines(4,2)],'linestyle','--','Color','green');
line([lines(1,3) lines(3,3)],[lines(2,3) lines(4,3)],'linestyle','--','Color','green');
line([lines(1,4) lines(3,4)],[lines(2,4) lines(4,4)],'linestyle','--','Color','green');
xlim([-1 5])
ylim([-5 5])

figure
plot(poseW(1,:),poseW(2,:))
line([lines(1,1) lines(3,1)],[lines(2,1) lines(4,1)],'linestyle','--','Color','green');
line([lines(1,2) lines(3,2)],[lines(2,2) lines(4,2)],'linestyle','--','Color','green');
line([lines(1,3) lines(3,3)],[lines(2,3) lines(4,3)],'linestyle','--','Color','green');
line([lines(1,4) lines(3,4)],[lines(2,4) lines(4,4)],'linestyle','--','Color','green');
xlim([-1 5])
ylim([-5 5])

% %Plot of lines from world pose
% subplot(2,2,1)
% line([lines(1,1) lines(3,1)],[lines(2,1) lines(4,1)],'linestyle','--','Color','green');
% xlim([-10 10])
% ylim([-10 5])
% 
% subplot(2,2,2)
% line([lines(1,2) lines(3,2)],[lines(2,2) lines(4,2)],'linestyle','--','Color','green');
% xlim([-10 10])
% ylim([-10 5])
% 
% subplot(2,2,3)
% line([lines(1,3) lines(3,3)],[lines(2,3) lines(4,3)],'linestyle','--','Color','green');
% xlim([-10 10])
% ylim([-10 5])
% 
% subplot(2,2,4)
% line([lines(1,4) lines(3,4)],[lines(2,4) lines(4,4)],'linestyle','--','Color','green');
% xlim([-10 10])
% ylim([-10 5])







