function transform = findTransform(odoPose, pose)
% transform = FINDTRANSFORM(odoPose,pose)
% Find the transformation from the world coordinates to the odometry
% coordinates given a pose in the odometry coordinates (odoPose) and the
% same point in the world coordinates (pose). The output (transform) is
% simply the origo of the odometry coordinates in the world coordinates



transformTheta = odoPose(3)-pose(3);
transformX = odoPose(1)-cos(transformTheta)*pose(1)+sin(transformTheta)*pose(2);
transformY = odoPose(2)-sin(transformTheta)*pose(1)-cos(transformTheta)*pose(2);

transform = [transformX; transformY; transformTheta];

%transform = [0;0;0];
end