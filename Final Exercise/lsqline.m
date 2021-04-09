function line = lsqline(points)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
x = points(1,:);
y = points(2,:);

x_mean = sum(x)/length(x);
y_mean = sum(y)/length(y);

num = 2*sum(x)*sum(y)-2*length(x)*dot(x,(y));
den = sum(x)*sum(x)-sum(y)*sum(y)-length(x)*dot(x,(x))+length(y)*dot(y,y);

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

display(alpha)

line = [alpha r];


end

