function sigmazp = linecov(zw, pose, poseCov)
%Calculates the covariance matrix of the predicted line features
%zw = is the line features in world coordinate
%pose = predicted pose in world coordinates
%poseCov = covariance matrix of the predicted robot pose
%% Constant
global lsrRelPose % The laser scanner pose in the robot frame is read globally


%% Calculations
H = [0 0 -1; -cos(zw(1)) -sin(zw(1)) lsrRelPose(1)*sin(-zw(1)+pose(3))+lsrRelPose(2)*cos(-zw(1)+pose(3))];

sigmazp = H*poseCov*transpose(H);


end

