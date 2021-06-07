addpath('../extras')
constants;
pose=[0.4 0.2 pi/4]'
posecov=[0.001 0 0;
         0.00 0.001 0
         0  0  0.001];
worldlines=[0 1.0;
            pi/2 0.9]';
laserlines=[-pi/4-0.01 0.4020+0.01
            pi/4+0.02 0.5020-0.005]';
matchResult=match( pose, posecov, worldlines, laserlines )

matchResultcor=[       0    1.5708
    1.0000    0.9000
   -0.0100    0.0200
    0.0100   -0.0050
    1.0000    2.0000]
%[matchResultcor matchResult] 
pause
[ poseOut, poseCovOut ] = measurementUpdate( pose, posecov, matchResult)
poseOutcor =[
    0.3925
    0.2039
    0.7828]
poseCovOutcor =1.0e-03 * [
    0.2923   -0.0065    0.0463
   -0.0065    0.2923   -0.0463
    0.0463   -0.0463    0.3272]