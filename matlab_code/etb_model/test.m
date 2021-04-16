close all
load('test30.mat');
RMSE30 = RMSE;
load('test25.mat');
RMSE25 = RMSE;

for i = (1:size(RMSE,2))
    RMSEAVG(1,i) = RMSE(1,i);
    RMSEAVG(2,i) = RMSE(2,i);
    RMSEAVG(3,i) = ((RMSE25(3,i)*.5) + (RMSE30(3,i)*.5));
end
figure(1);
hold on;
scatter(1:length(RMSE),RMSE25(3,:),'DisplayName','25 PWM');
scatter(1:length(RMSE),RMSE30(3,:),'DisplayName', '30 PWM');
scatter(1:length(RMSE),RMSEAVG(3,:),'DisplayName', 'AVERAGE');
hold off;

for i=1:size(RMSEAVG,2)
    [a,b] = min(RMSEAVG(3,:));
    RMSEAVG(4:6,i) = RMSEAVG(1:3,b);
    RMSEAVG(7,i) = RMSE30(3,b);
    RMSEAVG(8,i) = RMSE25(3,b);
    RMSEAVG(1:3,b) = 99999;
end