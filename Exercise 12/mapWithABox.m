
map = zeros(46);
box = ones(50/5,30/5);

[r,c]=size(box);
[r2,c2]=size(map);

map(r2/2-r/2:r2/2+r/2,c2/2-c/2:c2/2+c/2)=1;

se = ones(9);
map_dil = imdilate(map,se);

startPose = [r2/2 1];
endPose = [r2/2 46];