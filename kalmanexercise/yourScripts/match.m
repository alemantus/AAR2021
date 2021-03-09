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


%Predicted (Found by RANSAC): h_i(worldLines, pose, lsrRelPose)
%(alpha_L,r_L)

%Measured: laserLines 



%Innovation (measured - predicted)


% The varAlpha and varR are the assumed variances of the parameters of
% the extracted lines, they are read globally.
global varAlpha varR
 
%% Calculation
sigmaR = [varAlpha 0; 0 varR];



%[projectedLine, lineCov] = projectToLaser(worldLines(:,1), pose, poseCov);


matchResult = zeros(5,length(worldLines));
innovation = zeros(2,length(worldLines));
projectedLine = zeros(2,length(worldLines));
%lineCov = zeros(1,length(worldLines));

for i = 1:length(laserLines(1,:))
    [projectedLine(:,i), lineCov] = projectToLaser(worldLines(:,i), pose, poseCov);
    lineCov
end

lineCov
laserLines
projectedLine

for i = 1:length(laserLines(1,:))
    innovation(1,i) = laserLines(1,i)-projectedLine(1,i);
    innovation(2,i) = laserLines(2,i)-projectedLine(2,i);
    
    matchResult(:,i) = [worldLines(1,i); worldLines(2,i); innovation(1,i); innovation(2,i); 0];

end

crit = zeros(1,length(laserLines(1,:)));

for i = 1:length(laserLines(1,:))
    crit(i) = transpose(innovation(:,i))*inv(lineCov(i)+sigmaR)*innovation(:,i);
    if 4 >= crit(i)
        matchResult(5,i) = 1;
        display("Found match")
        pause
    else 
        matchResult(5,i) = 0;
    end
matchResult
end
