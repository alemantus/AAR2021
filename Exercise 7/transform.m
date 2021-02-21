function [poseW] = transform(systempose_w, xL, yL, thetaL)
%Transforming coordinates of laser pose to world pose
% See Exercise 7 Problem 3

if(length(systempose_w) ==2)
    poseWXY = zeros(2,1);
    poseWTheta = 0;
    
    poseWXY = [cos(thetaL) -sin(thetaL) ; sin(thetaL) cos(thetaL)]*systempose_w(:)+[xL; yL];
    poseWTheta = thetaL + atan2(systempose_w(2),systempose_w(1));
    
    poseW = [poseWXY ; poseWTheta];

else


    poseWXY = zeros(2, length(systempose_w));
    poseWTheta = zeros(1,length(systempose_w));


    for i = 1:length(poseWXY)
        poseWXY(:,i) = [cos(thetaL) -sin(thetaL) ; sin(thetaL) cos(thetaL)]*systempose_w(:,i)+[xL; yL];
        poseWTheta(1,i) = thetaL + atan2(systempose_w(2,i),systempose_w(1,i));
    end

    poseW = [poseWXY ; poseWTheta];

end