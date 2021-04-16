close all
clear

scatter(0,0,'d');
hold on
line([-3,0],[0,-3],'Color','red')
hold on
line([5,5],[-10,10],'Color','yellow')
hold on
line([-10,10],[3,3],'Color','blue')

legend("Car", "line x+y+3=0", "line x=5", "line y=3");