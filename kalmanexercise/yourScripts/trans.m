function odoTargetPose = trans(transform,targetPose)
% odoTargetPose = trans(transform,targetPose)
% Transform a given point in world coordinates (targetPose) to odometry
% coordinates, using the origo of the odometry coordinates in world
% coordinates (transform).

odoTargetPoseTheta = targetPose(3)+transform(3);
odoTargetPoseX = cos(transform(3))*targetPose(1) - sin(transform(3))*targetPose(2) + transform(1);
odoTargetPoseY = sin(transform(3))*targetPose(1) + cos(transform(3))*targetPose(2) + transform(1);

odoTargetPose = [odoTargetPoseX; odoTargetPoseY; odoTargetPoseTheta];


%odoTargetPose = [0;0;0];
end