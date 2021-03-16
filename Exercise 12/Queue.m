
% Create a cost map
cost = zeros(size(map));

% Find index of goal and current pos:
[x, goali] = min(abs(xaxis - goal(1)));
[y, goalj] = min(abs(yaxis - goal(2)));
[x, posi] = min(abs(xaxis - pos(1)));
[y, posj] = min(abs(yaxis - pos(2)));


open = [goali goalj];
cost(goali, goalj) = 2;
%neighbours = [ 1 0; 0 1; -1 0; 0 -1];  % immediate neighbourss
neighbours = [ 1 -1; 1 0; 1 1; 0 -1; 0 0; 0 1; -1 -1; -1 0; -1 1 ];

%FIFO Queueing
while size(open,1) ~= 0
  
  %For all neighbouring points neighbours of cp
  for cp=1:size(neighbours,1) 
    % Calculate index for current neighbours cell:
    nbi = open(1,:)+neighbours(cp,:);


    % Make sure the neighbour cell is not an obstacle 
    if occ(nbi(1), nbi(2)) == 1
      continue
    end

    % Set the cost and add the neighbours to the open set
    cost(nbi(1), nbi(2)) = cost(open(1,1), open(1,2)) + 1;
    open(size(open,1)+1,:) = nbi;
  end

  % Pop the top open cell from the queue
  open = open(2:end,:);
end

