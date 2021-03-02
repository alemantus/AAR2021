function line = lsqLine(points)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
x = points(1,:);
y = points(2,:);

x_mean = sum(x)/length(x);
y_mean = sum(y)/length(y);

num = 2*sum(x)*sum(y)-2*length(x)*x*transpose(y);
den = sum(x)*sum(x)-sum(y)*sum(y)-length(x)*x*transpose(x)+length(y)*y*transpose(y);

alpha = atan2(num,den)/2;

r = x_mean*cos(alpha)+y_mean*sin(alpha);

if r < 0
    r = -r;
    if alpha < 0
        alpha = alpha+pi;
    else
        alpha = alpha-pi;
    end
end


line = [alpha r];


end

