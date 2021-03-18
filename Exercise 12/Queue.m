
% Create a map map
map = zeros(size(map));

% Find index of goal and current pos:
[x, goali] = min(abs(xaxis - goal(1)));
[y, goalj] = min(abs(yaxis - goal(2)));
[x, posi] = min(abs(xaxis - pos(1)));
[y, posj] = min(abs(yaxis - pos(2)));


map2 = [goali goalj];
map(goali, goalj) = 2;
%The neighbouring cell's relative coordinates to the current point
neighbours = [ 1 0;  0 1; 0 -1; -1 0;  -1 -1; -1 1; 1 -1;  1 1];

dist =       [  1;  1;  1;   1;    1.41;  1.41;  1.41;   1.41];

%FIFO Queueing
while size(queue,1) ~= 0

  %All neighbouring points of our current cell (the top of the Queue) are
  %calculated by adding the values from "neighbours" to the current map
  %coordinates.
  for i=1:size(neighbours,1) 
    
    nbi = (neighbours(i,:) + queue(1,:));
    
    %Calculate the distance to the neighbour cell?
    d = map(nbi) + dist(i);
    
    if (map(nbi) == 0)
        map(nbi) = d;
        queue(size(queue,1)+1,:) = nbi;
    elseif ( map(nbi) > d)
        map(nbi) = d;
    end
    
  end

  % Pop the top map cell from the queue
  queue = queue(2:end,:);
end



