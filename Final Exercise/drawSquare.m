close all; clear; clc;

%Orientation of box:
th = 10;

%Placement of center:
x_c = 0.3;
y_c = 0.3;

%Size
L = 0.3;
B = 0.2;

a = [x_c-L/2 y_c+B/2]; 
b = [x_c+L/2 y_c+B/2];
c = [x_c-L/2 y_c-B/2];
d = [x_c+L/2 y_c-B/2];

a_new(1) = (a(1)-x_c)*cosd(th)-(a(2)-y_c)*sind(th)+x_c;
a_new(2) = (a(1)-x_c)*sind(th)+(a(2)-y_c)*cosd(th)+y_c;

b_new(1) = (b(1)-x_c)*cosd(th)-(b(2)-y_c)*sind(th)+x_c;
b_new(2) = (b(1)-x_c)*sind(th)+(b(2)-y_c)*cosd(th)+y_c;

c_new(1) = (c(1)-x_c)*cosd(th)-(c(2)-y_c)*sind(th)+x_c;
c_new(2) = (c(1)-x_c)*sind(th)+(c(2)-y_c)*cosd(th)+y_c;

d_new(1) = (d(1)-x_c)*cosd(th)-(d(2)-y_c)*sind(th)+x_c;
d_new(2) = (d(1)-x_c)*sind(th)+(d(2)-y_c)*cosd(th)+y_c;



%Defining lines
%Line 1 (Long 1)
lines(1,1) = a_new(1);
lines(2,1) = a_new(2);
lines(3,1) = b_new(1);
lines(4,1) = b_new(2);

%Line 2 (Short 1)
lines(1,2) = a_new(1);
lines(2,2) = a_new(2);
lines(3,2) = c_new(1);
lines(4,2) = c_new(2);

%Line 3 (Long 2)
lines(1,3) = c_new(1);
lines(2,3) = c_new(2);
lines(3,3) = d_new(1);
lines(4,3) = d_new(2);

%Line 4 (Short 2) 
lines(1,4) = b_new(1);
lines(2,4) = b_new(2);
lines(3,4) = d_new(1);
lines(4,4) = d_new(2);

%Scanner pose
x = -0.2;
y = 0;
theta = 0;

%Other input
maxDistance = 1.2;
resol = 0.36;
field_of_view = 180;

%Calling laserscanner
pol = laserscanHighresol(x, y, theta, lines, maxDistance, resol, field_of_view);

%Converting to cartesian
carth = polar2carth(pol);

%Transforming laser to global
poseW = transform(carth, x, y, theta);

%Estimate square position
poseSquare = squareDetect(pol, poseW, maxDistance);



figure
hold on
plot(poseW(1,:),poseW(2,:))
line([lines(1,1) lines(3,1)],[lines(2,1) lines(4,1)],'linestyle','-','Color','green');
line([lines(1,2) lines(3,2)],[lines(2,2) lines(4,2)],'linestyle','-','Color','green');
line([lines(1,3) lines(3,3)],[lines(2,3) lines(4,3)],'linestyle','-','Color','green');
line([lines(1,4) lines(3,4)],[lines(2,4) lines(4,4)],'linestyle','-','Color','green');
scatter(poseSquare(1),poseSquare(2))

legend('Laser coordinates','World coordinates', '', '', '', 'Center of square')
ylabel('y-direction [m]')
xlabel('x-direction [m]')


%xlim([-4 4])
%ylim([-4 4])


xlim([0 maxDistance])
ylim([0 maxDistance])
hold off