clc
%clear all
%close all
load('simulationData30.mat');
RMSEdata = 0;
RMSE = 0;
avg(1:size(inputTimeData,1)-1,1) = inputTimeData(2:end,1);
avg(:,2)=0;
index = 0;
for i = 2:size(inputTimeData,2)
    if simulationData(1,1) == inputTimeData(1,i)
        avg(:,2) = avg(:,2) + inputTimeData(2:end,i);
        index = index+1;
    end
end
avg(:,2) = avg(:,2)./2;

for k = 2:size(simulationData,2)    
    searchStart = 4;
	for i= 1:size(avg,1)
        for j = searchStart:size(simulationData,1)
            if simulationData(j,1) == avg(i,1)
                RMSEdata(i,1) = avg(i,1);
                RMSEdata(i,k) = (simulationData(j,k)-avg(i,2))^2;
                searchStart = j;
                break
            end
        end
        continue
    end
    RMSE(1,k-1) = simulationData(2,k);
    RMSE(2,k-1) = simulationData(3,k);
    RMSE(3,k-1) = sqrt(sum(RMSEdata(:,k))/size(RMSEdata,1));
end
                