function transform = findTransform(odoPose, pose)
% transform = FINDTRANSFORM(odoPose,pose)
% Find the transformation from the world coordinates to the odometry
% coordinates given a pose in the odometry coordinates (odoPose) and the
% same point in the world coordinates (pose). The output (transform) is
% simply the origo of the odometry coordinates in the world coordinates



transformTheta = odoPose(3)-pose(1);

transformXY = [-cos(transform(3)) sin(transform(3)); -sin(transform(3)) -cos(transform(3))]*[pose(1); pose(2)]+[odoPose(1); odoPose(2)];

transform = [transformXY; transformTheta];

%transform = [0;0;0];
end