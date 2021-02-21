function [carth] = polar2carth(pol)
%Converting polar to cartesian coordinates
carth = zeros(2,length(pol));

for i = 1:length(carth)
    carth(1,i) = pol(2,i)*cos(pol(1,i));
    carth(2,i) = pol(2,i)*sin(pol(1,i));
end
end

