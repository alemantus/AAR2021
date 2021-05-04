%Make something that goes to the start field with 45 degrees angle first.


%Find the box. $l9 is x, $l10 is y, and $l11 is theta, $l12 is the angle of the corner, $l15 is the length of the longest
%observed line, $l9 is the length of the shortest observed line, $l17 is the relative angle to the longest observed
%line, $l18 is the relative angle of the shortest observed line.

fwd 0.5

turn -90 @v0.5
fwd 0.15
drive @v0.5 :($irdistleft < 1.0)
stop


laser "scanpush cmd = 'zoneobst' "
wait 1
log "$l9" "$l10" "$l11"

%Final pose

finalX = 0
finalY = 0
finalTheta = 0

X = $l9
Y = $l10
theta = $l11

X = X - 0.5
%Y = Y - 0.5
eval X; Y; theta

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

X = $l9
Y = $l10
theta = $l11


log "$odox" "$odoy" "$odoth"
%Final pose
%X = $l9
%Y = $l10
%theta = $l11
%cornerAngle = $l12
%longestLength = $l105
%shortestLength = $l106
%longestAngle = $l107
%shortestAngle = $l108
object1 = $l13
object2 = $l14
object3 = $l15
object4 = $l16


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
followwall "l" 0.3 :($drivendist > 0.9)
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


turn -90
followwall "l" 0.3 :($drivendist > 0.3)
stop
turn 90

goto "zoning"






%Squares
label "Object1"
%Print out "The object is object 1"

laser "scanpush cmd = 'zoneobst' "
wait 1
X = $l9
Y = $l10
theta = $l11
object = 1
eval X; Y; theta
trans $odox $odoy $odoth X Y theta
finalX = $res0
finalY = $res1
finalTheta = $res2


goto "stop"

label "Object2"
%Print out "The object is object 2"
laser "scanpush cmd = 'zoneobst' "
wait 1
X = $l9
Y = $l10
theta = $l11
eval X; Y; theta
eval $odox; $odoy; $odoth
object = 2
trans $odox $odoy $odoth X Y theta
finalX = $res0
finalY = $res1
finalTheta = $res2

goto "stop"

%Triangles/Triangulation

label "Object3"
%Print out "The object is object 3"
object = 3
goto "Triangulation"



label "Object4"
%Print out "The object is object 4"
object = 4
goto "Triangulation"


label "Triangulation"



laser "scanpush cmd = 'zoneobst' "
wait 1

X = $l9
Y = $l10
theta = $l11
cornerAngle = $l12

cornerX = $l17
cornerY = $l18

eval cornerAngle

if  ((cornerAngle < 1.6) & (cornerAngle > 1.4)) "finish2" %Break out of the loop when we have seen 4 sides

i = i + 1

%if (i > 3) "adjustPosition" %Break out of the loop when we have seen 4 sides


turn -90
followwall "l" 0.3 :($drivendist > 0.6)
stop
turn 90

goto "Triangulation"



label "finish2"
trans $odox $odoy $odoth cornerX cornerY theta
finalX = $res0
finalY = $res1
finalTheta = $res2

goto "stop"




label "stop"

eval object

eval finalX; finalY; finalTheta

stop
