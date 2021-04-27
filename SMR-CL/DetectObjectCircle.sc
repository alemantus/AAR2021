%Make something that goes to the start field with 45 degrees angle first.


%Find the box. $l1 is x, $l2 is y, and $l3 is theta, $l4 is the angle of the corner, $l5 is the length of the longest
%observed line, $l6 is the length of the shortest observed line, $l7 is the relative angle to the longest observed
%line, $l8 is the relative angle of the shortest observed line.


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



sum1 = 0
sum2 = 0
sum3 = 0
sum4 = 0

i = 0


label "zoning"

laser "scanpush cmd = 'zoneobst' "
wait 1

X = $l1
Y = $l2
theta = $l3


%log "$l1" "$l2" "$l3" "$l4" "$l5" "$l6" "$l7" "$l8" "$l9" "$l10" "$l11" "$l12"
log "$odox" "$odoy" "$odoth"
%Final pose
%X = $l1
%Y = $l2
%theta = $l3
%cornerAngle = $l4
%longestLength = $l5
%shortestLength = $l6
%longestAngle = $l7
%shortestAngle = $l8
object1 = $l9
object2 = $l10
object3 = $l11
object4 = $l12


sum1 = sum1 + object1
sum2 = sum2 + object2
sum3 = sum3 + object3
sum4 = sum4 + object4

eval sum1; sum2; sum3; sum4
eval $odox; $odoy; $odoth
eval X; Y; theta



i = i + 1
if (i > 4) "finish" %Break out of the loop when we have seen 4 sides

turn -90
followwall "l" 0.5 :($drivendist > 0.9)
stop
turn 90

goto "zoning"


label "finish"
i = 0

%Check object confidence:
if ((sum1 > sum2) & (sum1 > sum3) & (sum1 > sum4)) "Object1"
if ((sum2 > sum1) & (sum2 > sum3) & (sum2 > sum4)) "Object2"
if ((sum3 > sum1) & (sum3 > sum2) & (sum3 > sum4)) "Object3"
if ((sum4 > sum1) & (sum4 > sum3) & (sum4 > sum1)) "Object4"



followwall "l" 0.5 :($drivendist > 0.3)
stop


goto "zoning"






%Squares
label "Object1"
%Print out "The object is object 1"

laser "scanpush cmd = 'zoneobst' "
wait 1
X = $l1
Y = $l2
theta = $l3


object = 1
eval 1


eval X; Y; theta

trans $odox $odoy $odoth X Y theta
deltaX = $res0
deltaY = $res1
deltaTheta = $res2
eval deltaX; deltaY; deltaTheta


goto "stop"

label "Object2"
%Print out "The object is object 2"


laser "scanpush cmd = 'zoneobst' "
wait 1

X = $l1
Y = $l2
theta = $l3

eval X; Y; theta
eval $odox; $odoy; $odoth

object = 2
eval 2

trans $odox $odoy $odoth X Y theta
deltaX = $res0
deltaY = $res1
deltaTheta = $res2
eval deltaX; deltaY; deltaTheta

goto "stop"

%Triangles/Triangulation

label "Object3"
%Print out "The object is object 3"
object = 3

eval 3

goto "Triangulation"



label "Object4"
%Print out "The object is object 4"
object = 4

eval 4
goto "Triangulation"


label "Triangulation"



laser "scanpush cmd = 'zoneobst' "
wait 1

X = $l1
Y = $l2
theta = $l3
cornerAngle = $l4

cornerX = $l13
cornerY = $l14

eval cornerAngle

if  ((cornerAngle < 1.6) & (cornerAngle > 1.4)) "finish2" %Break out of the loop when we have seen 4 sides

i = i + 1

%if (i > 3) "adjustPosition" %Break out of the loop when we have seen 4 sides


turn -90
followwall "l" 0.5 :($drivendist > 0.6)
stop
turn 90

goto "Triangulation"



label "finish2"
trans $odox $odoy $odoth cornerX cornerY theta
deltaX = $res0
deltaY = $res1
deltaTheta = $res2
eval deltaX; deltaY; deltaTheta


label "stop"
stop
