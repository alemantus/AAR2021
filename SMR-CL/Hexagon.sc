%Implementing feedback algorithm for point to point


%Find the box. $l1 is x, $l2 is y, and $l3 is theta
laser "scanpush cmd = 'zoneobst' "
wait 1
log "$l1" "$l2" "$l3"

%Final pose
X = $l1
Y = $l2
theta = $l3

X = X - 0.5
%Y = Y - 0.5

drive X Y theta : ($targetdist < 0.25)
stop