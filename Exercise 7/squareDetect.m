function square = squareDetect(pol)


imgaussfilt(pol(2,:),1)


%L = length(pol(1,:))

%x = 0:1/L:L;
%g = gaussmf(x,[L*0.1 L*0.3]);
%y= conv(pol(2,:), g);


%gd = diff(g);




figure
plot(pol(2,:))



plot(x,y)







    