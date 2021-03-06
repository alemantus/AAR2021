% Get a laser scan
success = 0;
while(~success)
    [scan success] = getLaser(lsrSck,simulation);
end

%scan is in polar coordinates, convert it to cartesian coordinates
scanCar = [(cos(scan(1,:)).*scan(2,:));(sin(scan(1,:)).*scan(2,:))];

%Extract lines from the scan data
laserLines = ransacLines(scanCar, [maxNoOfLines noOfRandomCouples distThreshold minLineSupport minNoOfPoints]);

%Perform line matching
matchResult = match(pose, poseCov,worldLines, laserLines);
matchPose = pose; %Recording the pose during mathing for plotting purposes

%Update the pose estimate using the measured lines
[pose, poseCov] = measurementUpdate(pose,poseCov, matchResult);

% Move a bit
nTarget

switch nTarget
    case 0
        targetPose = [0; 0; 0];
        nTarget = nTarget+1;
    case 1
        targetPose = [0.5; 0.5; pi];
        nTarget = nTarget+1;
    case 2
        targetPose = [-0.5; 0.5; -pi/2];
        nTarget = nTarget+1;
    case 3
        targetPose = [-0.5; -0.5; 0];
        nTarget = nTarget+1;
    case 4
        targetPose = [0.5; -0.5; pi/2];
        nTarget = nTarget+1;
    case 5
        targetPose = [0.5; 0.5; pi];
        nTarget = nTarget+1;
    otherwise
        stop
%         nTarget = 1;
%         targetPose = [0.5; 0.5; pi];
%         nTarget = nTarget+1;
end
% Find the next waypoint in world coordinates and put it in targetPose

% targetPose = [0; 0; 0];
% targetPose = [0.5; 0.5; pi];
% targetPose = [-0.5; 0.5; -pi/2];
% targetPose = [-0.5; -0.5; 0];
% targetPose = [0.5; -0.5; pi/2];
% targetPose = [0.5; 0.5; pi];



%Find the transformation from the estimated world coordinates to the 
%odometry coordinates
transform = findTransform(odoPose, pose);

%Find the target pose in the odometry coordinates
odoTargetPose = trans(transform,targetPose);

%Drive to the waypoint while updating the pose estimation
[pose, poseCov, odoPose] = driveToWaypoint(mrcSck, pose, poseCov, odoPose, odoTargetPose,simulation);

