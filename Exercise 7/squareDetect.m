%function square = squareDetect(pol)


x= poseW(1,:)
y = poseW(2,:)

dist=pol(2,:);

for i = 1:length(dist)
    
    if dist(i) < 1.2
        startIndex = i;
        break;
    end
    
end


for i = length(dist):-1:1
    
    if dist(i) < 1.2
        endIndex = i;
        break;
    end
    
end



x(dist >= 1.2) = NaN;
y(dist >= 1.2) = NaN;
dist(dist>=1.2)=NaN

gdd=diff(imgaussfilt(dist,1),2);

[m, cornerIndex] = max(gdd);




%Index=dist < 1.2

%x=x(Index);
%y=y(Index);


points1 = [x(startIndex:cornerIndex); y(startIndex:cornerIndex)]

points2 = [x(cornerIndex:endIndex); y(cornerIndex:endIndex)]

line1 = lsqline(points1);

line2 = lsqline(points2);


length1 = sqrt((x(startIndex)-x(cornerIndex))^2 + (y(startIndex)-y(cornerIndex))^2);
length2 = sqrt((x(endIndex)-x(cornerIndex))^2 + (y(endIndex)-y(cornerIndex))^2);

if length1 > length2
   
    theta = line1(1)-pi/2;
    
    
else
    theta = line2(1)-pi/2;
    
end

%Center of square?


xcenter=(x(startIndex)+x(endIndex))/2
ycenter=(y(endIndex)+y(startIndex))/2


%L = length(pol(1,:))

%x = 0:1/L:L;
%g = gaussmf(x,[L*0.1 L*0.3]);
%y= conv(pol(2,:), g);


%gd = diff(g);





figure
plot(pol(2,:))

figure

plot(x,y)







    