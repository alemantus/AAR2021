function square = squareDetect(pol, poseW, maxlength)

x = poseW(1,:);
y = poseW(2,:);

%maxlength = 4;
dist=pol(2,:);

i=0;
startIndex = 0;
endIndex = 0;

for i = 1:length(dist)
    
    if dist(i) < maxlength
        startIndex = i;
        break;
    end
    
end


for i = length(dist):-1:1
    
    if dist(i) < maxlength
        endIndex = i;
        break;
    end
    
end



x(dist >= maxlength) = NaN;
y(dist >= maxlength) = NaN;
dist(dist>=maxlength)=NaN;

gdd=diff(imgaussfilt(dist,1),2);

cornerIndex = 0;
[m, cornerIndex] = max(gdd);




%Index=dist < 1.2

%x=x(Index);
%y=y(Index);


points1 = [x(startIndex:cornerIndex(1)); y(startIndex:cornerIndex(1))];

points2 = [x(cornerIndex(1):endIndex); y(cornerIndex(1):endIndex)];

line1 = lsqline(points1);

line2 = lsqline(points2);


length1 = sqrt((x(startIndex)-x(cornerIndex))^2 + (y(startIndex)-y(cornerIndex))^2);
length2 = sqrt((x(endIndex)-x(cornerIndex))^2 + (y(endIndex)-y(cornerIndex))^2);

if length1 > length2
   
    theta = line1(1)-pi/2;
    
    
else
    theta = line2(1)-pi/2;

end

xcenter=(x(startIndex)+x(endIndex))/2;
ycenter=(y(endIndex)+y(startIndex))/2;

square = [xcenter ycenter theta];