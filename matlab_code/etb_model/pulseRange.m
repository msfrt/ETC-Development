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
timeLengths =0;
table =0;
for i = (1:length(pulseCord))
    timeLengths(i) = length(pulseCord(i,1):pulseCord(i,2));
    table(1,1) = 0;
    table(1,i+1) = pulseCord(i,3);
    for j = (1:max(timeLengths))
        table(j+1,1) = round(t3(j)-t3(1),3);
    end
    for j = (1:pulseCord(i,2)-pulseCord(i,1))
        table(j+1,i+1) = ETC_throttlePosition1_pct_t3(pulseCord(i,1)+j);
    end
end
for i = (2:size(table,2))
    for j = (2:size(table,1))
        if table(j,i) == 0
            table(j,i) = table(j-1,i);
        end
    end
end
%%
table2(1,1:size(table,2)) =0
for i = 1:size(table,1)
    if (table(i,1) <= 2)
        table2(i,:) =table(i,:)
    end
    i
end


%signalTimeSeries = timeseries(table(:,2:size(table,2)),table(:,1))
plot(table(2:size(table,1),1),table(2:size(table,1),2:size(table,2)))
%%
figure(1);
hold on;
for i = 1:length(pulseCord)
    plot(t3(pulseCord(i,1):pulseCord(i,2))-t3(pulseCord(i,1)),ETC_throttlePosition1_pct_t3(pulseCord(i,1):pulseCord(i,2)))
end
legend(string(pulseCord(:,3)));
hold off;
save('pulseCord.mat','pulseCord');
inputTimeData = table;
save('inputTimeData.mat','inputTimeData')
