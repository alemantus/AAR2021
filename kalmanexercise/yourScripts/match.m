function [ matchResult ] = match(pose, poseCov, worldLines, laserLines )
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


%Predicted = pose (carth)
r_p = sqrt(pose(1)^2+pose(2)^2);
alpha_p = atan2(pose(2),pose(1));

%Measured = laserLines (polar)

%Innovation (measured - predicted)
Innovation1 = laserLines(1) - alpha_p;
Innovation2 = laserLines(2) - r_p;


% The varAlpha and varR are the assumed variances of the parameters of
% the extracted lines, they are read globally.
global varAlpha varR

    
%% Calculation
matchResult = zeros(5,length(laserLines));

for i = 1:lenght(laserLines)
    matchResult(:,i) = [worldLine(1,1); worldLine(2,1); innovation1(1); innovation1(2); i];

end

end
