clear;


% Create a map map
%map = zeros(10,10);
%map(1:7,3)=ones(7,1)*-1;
%map(3:10)=ones(8,1)*-1;
%goal=[9,9];
%start=[2,2];

map = zeros(46);
box = ones(50/5,30/5);

[r,c]=size(box);
[r2,c2]=size(map);

map(r2/2-r/2:r2/2+r/2,c2/2-c/2:c2/2+c/2)=1;

se = ones(9);
map = imdilate(map,se)*(-1);

start = [r2/2, 1];
goal = [r2/2, 45];


resolution = 0.05;



%The neighbouring cell's relative coordinates to the current point
neighbours = [ 1 0; 0 1; 0 -1; -1 0;  -1 -1; -1 1; 1 -1;  1 1];

dist =       [ 1;  1;  1;   1;    1.41;  1.41;  1.41;   1.41];

queue = [start(1) start(2)];

%FIFO Queueing


queiteration = 0;

while size(queue,1) ~= 0

  %All neighbouring points of our current cell (the top of the Queue) are
  %calculated by adding the values from "neighbours" to the current map
  %coordinates.
  for i=1:size(neighbours,1) 
    
    nbi = (neighbours(i,:) + queue(1,:));
    
    if (min(nbi) <= 0) %Check if the index is out of bounds?
        continue
    end
    if (max(nbi) > length(map)) %Check if the index is out of bounds?
        continue
    end
    
    %Calculate the distance to the neighbour cell?
    d = map(queue(1,1), queue(1,2)) + dist(i);
    
    if (map(nbi(1), nbi(2)) == 0)
        map(nbi(1), nbi(2)) = d;
        queue(size(queue,1)+1,:) = nbi;

%     elseif ( map(nbi(1), nbi(2)) > d)
%         map(nbi(1), nbi(2)) = d;
    end
    
  end
  

  
 

  
  % Pop the top map cell from the queue
  queue = queue(2:end,:);

  queiteration = queiteration+1;
end

map(start(1),start(2)) = 0

thetaOld = 0;
theta = 0;


display("check")

fileID = fopen('wavefront.sc','w');

%%Route
%we have a map, now we need a route - easiest to start from goal and move
%towards robot.
route = [goal(1) goal(2)];  

  
localMin=999;
j= 1;
globalCoordinate= 0;
while (route(end,1) ~= start(1) || route(end,2) ~= start(2))
  localMin=999;
  for i=1:size(neighbours,1) 

    nbi2 =  route(end,:) + neighbours(i,:);
    nbi2;
    if (map(nbi2(1),nbi2(2)) ~= -1)
        localMin_placeHolder = map(nbi2(1),nbi2(2));
        if (localMin_placeHolder < localMin)
            localMin = localMin_placeHolder;
            globalCoordinate = nbi2;
            localCoordinate = neighbours(i,:);

        end

    end

  end
route(size(route,1)+1,:) = globalCoordinate;

localCoordinate=localCoordinate*resolution;

localRoute(size(route,1)+1,:) = localCoordinate;


end
  

route = flip(route,1);

localRoute = flip(localRoute,1);

%The theta's have to be calculated forwards, not backwards
for i=1:size(localRoute,1)
    
  theta = ((atan2(-localRoute(i,1), -localRoute(i,2))))
  
  
  
  theta1 = theta - thetaOld;
  
  if abs(theta1) == pi/4 || abs(theta1) == 3/4*pi
      drivendist = 1.41;
  else
      drivendist = 1;
  end
  
  
  fprintf(fileID,"turn  "+string(theta1)+"  "+'"rad"'+" @v0.5" + '\n');
  fprintf(fileID,"fwd  "+string(drivendist*resolution)+ '\n');

  thetaOld = theta;
    
end


fclose(fileID);
  
  