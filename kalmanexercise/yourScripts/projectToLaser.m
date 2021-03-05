function [ projectedLine, lineCov ] = projectToLaser( worldLine,poseIn, covIn)
%[projectedLine, lineCov] = PROJECTTOLASER(worldLine,poseIn,covIn) 
%Project a word line to the laser scanner frame given the
%world line, the robot pose and robot pose covariance. Note that the laser
%scanner pose in the robot frame is read globally
%   worldLine: The line in world coordinates
%   poseIn: The robot pose
%   covIn: The robot pose covariance
%
%   projectedLine: The line parameters in the laser scanner frame
%   lineCov: The covariance of the line parameters

%% Constants
global lsrRelPose % The laser scanner pose in the robot frame is read globally


%% Calculation
%World line to robot
alpha_r = worldLine(1)-poseIn(3);
r_r = worldLine(2)-poseIn(1)*cos(worldLine(1))-poseIn(2)*sin(worldLine(1));

alpha_l = alpha_r-lsrRelPose(3);
r_l = r_r-lsrRelPose(1)*cos(alpha_r)-lsrRelPose(2)*sin(alpha_r);

projectedLine = [alpha_l r_l];

lineCov = linecov(worldLine, poseIn, covIn);

%lineCov = zeros(2,2);
end
