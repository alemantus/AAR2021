%Implementing feedback algorithm for point to point



%log "$odox" "$odoy" "$odoth"

%Robot parameters
w = 0.26
r = 0.035

%Find the box. $l1 is x, $l2 is y, and $l3 is theta
laser "scanpush cmd = 'zoneobst' "
wait 1
log "$l1" "$l2" "$l3"

%Final pose
X = $l1
Y = $l2
theta = $l3



%Controller parameters
k1 =  0.3
k2 = 0.8
k3 = -0.35

%Rho and alpha init
rho = 1
alpha = 1

%Update prorgam to also drive backward?

%Condition for looping
label "back"
if(rho>0.01 | alpha>0.02) "program"
stop


%Program execution
label "program"

%Use relative coordinates instead of global?


%Using global coordinates, we must invtrans:
invtrans X Y theta $odox $odoy $odoth
deltaX = -$res0
deltaY = -$res1
deltaTheta = $res2

%Using relative coordinates, we should be able to give l1 l2 and l3


rho = sqrt((deltaX*deltaX)+(deltaY*deltaY))
alpha = -deltaTheta + atan2(deltaY,deltaX)
beta = -deltaTheta - alpha
v = k1*rho
if (v < 0.005) "setSpeedZero"
label "backInProgram"
omega = k2*alpha + k3*beta
speedR = (v + omega*w*0.5)
speedL = (v - omega*w*0.5)
motorcmds speedL speedR
goto "back"

label "setSpeedZero"
v = 0
stop