function [returnPose,tvec] = linedrive(pose, targetPose, robotpar, ts)
krho=0.3;
kalpha=0.8;
kbeta=-0.35;
tvec=[]
returnPose=pose;
thetaTW = targetPose(3);
R = [cos(thetaTW) sin(thetaTW); -sin(thetaTW) cos(thetaTW)];
temp = [pose(1) - targetPose(1); pose(2)-targetPose(2)];
poseT = [R*temp; pose(3) - thetaTW];

rho = sqrt(poseT(1)^2 + poseT(2)^2)
alpha = - poseT(3) + atan2(-poseT(2), -poseT(1))
beta = - poseT(3) - alpha
if alpha >= -pi/2 && alpha <= pi/2
    
    while(abs(rho) > 0.01 || abs(alpha) > 0.02)
        thetaTW = targetPose(3);
        R = [cos(thetaTW) sin(thetaTW); -sin(thetaTW) cos(thetaTW)];
        temp = [pose(1) - targetPose(1); pose(2)-targetPose(2)];
        poseT = [R*temp; pose(3) - thetaTW];
        rho = sqrt(poseT(1)^2 + poseT(2)^2);
        alpha = - poseT(3) + atan2(-poseT(2), -poseT(1));
        beta = - poseT(3) - alpha;
        v = krho*rho; %This is what we previously called wheelspeed
        omega = kalpha*alpha + kbeta*beta;
        
        wheelspeed(1) = (v + omega*robotpar(1)*0.5)/robotpar(2);
        wheelspeed(2) = (v -omega*robotpar(1)*0.5)/robotpar(3);

        [temppose, tvec] = kinstep(pose, robotpar, ts, ts, wheelspeed);
        pose=temppose';
        returnPose= [returnPose; pose];

    end
else
    while(abs(rho) > 0.01 || abs(alpha) > 0.02)
        thetaTW = targetPose(3);
        %Reverse each sign of R
        R = [-cos(thetaTW) -sin(thetaTW); sin(thetaTW) -cos(thetaTW)];
        temp = [pose(1) - targetPose(1); pose(2)-targetPose(2)];
        poseT = [R*temp; pose(3) - thetaTW];
        rho = sqrt(poseT(1)^2 + poseT(2)^2);
        alpha = - poseT(3) + atan2(-poseT(2), -poseT(1));
        beta = - poseT(3) - alpha;
        v = -krho*rho; %The sign of v is reversed
        omega = kalpha*alpha+kbeta*beta;

        wheelspeed(1) = (v + omega*robotpar(1)*0.5)/robotpar(2);
        wheelspeed(2) = (v -omega*robotpar(1)*0.5)/robotpar(3);

        [temppose, tvec] = kinstep(pose, robotpar, ts, ts, wheelspeed);
        pose=temppose';
        returnPose= [returnPose; pose];
    end
end
display("distance to point: "+rho)
