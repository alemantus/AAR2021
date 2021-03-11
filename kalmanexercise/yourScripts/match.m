function [matchResult] = match(pose, poseCov, worldLines, laserLines )
% [matchResult] = MATCH(pose,poseCov,worldLines,laserLines)
%   This function matches the predicted lines to the extracted lines. The
%   criterion for a match is the mahalanobis distance between the (alpha,
%   r) parameters of the predicted and the extracted lines. The arguments
%   are:
%       pose: The estimated robot pose given as [x,y,theta]
%       poseCov: The estimated covariance matrix of the robot pose
%       worldLines: Known world lines in world coordinates, given as
%       [alpha;r] for each line. Number of rows = number of lines
%       laserLines: Lines extracted from the laser scan. Given as [alpha;r]
%       for each line. Number of rows = number of lines
%
%       matchResult: A (5xnoOfWorldLines) matrix whose columns are 
%       individual pairs of line matches. It is structured as follows:
%       matchResult = [ worldLine(1,1) , worldLine(1,2) ...  ]
%                     [ worldLine(2,1) , worldLine(2,2)      ]
%                     [ innovation1(1) , innovation2(1)      ]
%                     [ innovation1(2) , innovation2(2)      ]
%                     [ matchIndex1    , matchIndex2    ...  ]
%           Note that the worldLines are in the world coordinates!


%Predicted: h_i(worldLines, pose, lsrRelPose)
%(alpha_L,r_L)

%Measured (Found by RANSAC): laserLines 



%Innovation (measured - predicted)


% The varAlpha and varR are the assumed variances of the parameters of
% the extracted lines, they are read globally.
global varAlpha varR
 
%% Calculation
sigmaR = [varAlpha 0; 0 varR];
%sigmaR = zeros(2,2);


laserLinesA = zeros(2,length(worldLines));

for i=1:length(laserLines(1,:))
    laserLinesA(:,i) = laserLines(:,i);
end


[projectedLine1, lineCov1] = projectToLaser(worldLines(:,1), pose, poseCov);
[projectedLine2, lineCov2] = projectToLaser(worldLines(:,2), pose, poseCov);
[projectedLine3, lineCov3] = projectToLaser(worldLines(:,3), pose, poseCov);
[projectedLine4, lineCov4] = projectToLaser(worldLines(:,4), pose, poseCov);


innovation1 = laserLinesA(:,1)-projectedLine1;
innovation2 = laserLinesA(:,2)-projectedLine2;
innovation3 = laserLinesA(:,3)-projectedLine3;
innovation4 = laserLinesA(:,4)-projectedLine4;


matchResult(:,1) = [worldLines(1,1); worldLines(2,1); innovation1(1); innovation1(2); 0];
matchResult(:,2) = [worldLines(1,2); worldLines(2,2); innovation2(1); innovation2(2); 0];
matchResult(:,3) = [worldLines(1,3); worldLines(2,3); innovation3(1); innovation3(2); 0];
matchResult(:,4) = [worldLines(1,4); worldLines(2,4); innovation4(1); innovation4(2); 0];



crit1 = transpose(innovation1)*inv(lineCov1+sigmaR)*innovation1;
crit2 = transpose(innovation2)*inv(lineCov2+sigmaR)*innovation2;
crit3 = transpose(innovation3)*inv(lineCov3+sigmaR)*innovation3;
crit4 = transpose(innovation4)*inv(lineCov4+sigmaR)*innovation4;

measured = [laserLinesA(:,1) laserLinesA(:,2) laserLinesA(:,3) laserLinesA(:,4)]
predicted = [projectedLine1 projectedLine2 projectedLine3 projectedLine4]


crit1
crit2
crit3
crit4


if 4>= crit1
    matchResult(5,1) = 1;
elseif 4>= crit2
    matchResult(5,2) = 1;
elseif 4>= crit3
    matchResult(5,3) = 1;
elseif 4>= crit4
    matchResult(5,4) = 1;
end


if sum(matchResult(5,:)) >= 1
    disp("MATCH FOUND!")
    %matchResult
end
matchResult
end
