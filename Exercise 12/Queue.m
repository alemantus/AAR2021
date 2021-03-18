clear;


% Create a map map
map = zeros(10,10);
map(1:7,3)=ones(7,1);
map(3:10)=ones(8,1);
goal=[2,2];
start=[9,9];


%The neighbouring cell's relative coordinates to the current point
neighbours = [ 1 0;  0 1; 0 -1; -1 0;  -1 -1; -1 1; 1 -1;  1 1];

dist =       [  1;  1;  1;   1;    1.41;  1.41;  1.41;   1.41];

queue = [9 9]

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

    elseif ( map(nbi(1), nbi(2)) > d)
        map(nbi(1), nbi(2)) = d;
    end
    
  end

  
  disp(length(queue))
  
  
  % Pop the top map cell from the queue
  queue = queue(2:end,:);

  queiteration = queiteration+1;
end



