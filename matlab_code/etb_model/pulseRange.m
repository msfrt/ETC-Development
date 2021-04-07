close all
load('Recorder_2021-04-01_23-18-08')

%% Get Ranges
index=1;
for i= 2:length(ETC_motorAPWM_t2)
       if (ETC_motorAPWM_t2(i)- ETC_motorAPWM_t2(i-1) > 0)
           pulseCord(index,1) = i;
           pulseCord(index,3)= ETC_motorAPWM_t2(i);
       elseif (ETC_motorAPWM_t2(i)- ETC_motorAPWM_t2(i-1) < 0)
           pulseCord(index,2) = i;
           index = index + 1;
       end
end
%% 
timeLengths =0
table =0;
for i = (1:length(pulseCord))
    timeLengths(i) = length(pulseCord(i,1):pulseCord(i,2))
    for j = (1:max(timeLengths))
        table(j,1) = t3(j)-t3(1);
    end
    for j = (1:pulseCord(i,2)-pulseCord(i,1))
        table(j,i+1) = ETC_throttlePosition1_pct_t3(pulseCord(i,1)+j);
    end
end
signalTimeSeries = timeseries(table(:,2:size(table,2)),table(:,1))
plot(signalTimeSeries)
%%
figure(1);
hold on;
for i = 1:length(pulseCord)
    plot(t3(pulseCord(i,1):pulseCord(i,2))-t3(pulseCord(i,1)),ETC_throttlePosition1_pct_t3(pulseCord(i,1):pulseCord(i,2)))
end
legend(string(pulseCord(:,3)));
hold off;
save('pulseCord.mat','pulseCord');
