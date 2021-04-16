clear all
close all
open_system('etb_Model_Sweep');
%load('Recorder_2021-04-01_23-18-08.mat');
load('inputTimeData.mat');

%% prepare sims
Simulink.sdi.clear;
dutyCyclePWM = 30;
springPreload = 780;
springConst = 300;
springPreloadRange = 41;
springConstRange = 41;
numberOfModels = springPreloadRange * springConstRange;
simIn(1:numberOfModels) = Simulink.SimulationInput('etb_Model_Sweep');
simIn(1:numberOfModels) = simIn(1:numberOfModels).setVariable('dutyCyclePWM',dutyCyclePWM);
simulationData(1,1) = dutyCyclePWM;
for i=1:springConstRange
    for a=1:springPreloadRange
        modelNum = (i-1)*springPreloadRange + a;
        springConstValue = 129+i;
        springPreloadValue = 529+a;
        %simIn(modelNum) = Simulink.SimulationInput('etb_Model_Sweep');
        simIn(modelNum) = simIn(modelNum).setVariable('springConst',springConstValue);
        simIn(modelNum) = simIn(modelNum).setVariable('springPreload',springPreloadValue);
        
        simulationData(2,modelNum+1) = springConstValue;
        simulationData(3,modelNum+1) = springPreloadValue;
    end
    %springPreloadValue = 480+(20*i);
    %simIn(i) = Simulink.SimulationInput('etb_Model_Sweep');
    %simIn(i) = simIn(i).setVariable('springPreload',springPreloadValue);
    i
end
%% run sim
set_param('etb_Model_Sweep','StopTime',string(6));
%set_param('etb_Model_Sweep','FixedStep',string(inputTimeData(3,1)-inputTimeData(2,1)));
simOutputs = sim(simIn,'ShowSimulationManager','on','ShowProgress','on');

%% convert data
%runIDs = Simulink.sdi.getAllRunIDs();
%figure(1);
%hold on;
%legendText = single.empty(0,length(runIDs));
for i = 1:length(simOutputs)
    %Run = Simulink.sdi.getRun(runIDs(i));
    %signal = getSignalByIndex(Run,6);
    %a= signal.Values();
    a= simOutputs(i).logsout.get('throttleBladePositionPercent').Values;
    i
    if i == 1
        simulationData(4:length(a.time())+3,1) = round(a.time(),3);
    end
    
    for j = 1:length(a.time())
        
        simulationData(j+3,i+1) = round(a.data(j),2);
    end
    %plot(simulationData(4:end,1),simulationData(4:end,i+1));
    %legendText(i)= string(i);
end
%t3(2313:2704) = t3(2313:2074) ;
%plot((t3(2314:2703)- t3(2314)), ETC_throttlePosition1_pct_t3(2314:2703));
%legend(legendText);
%title("Percentage of Throttle Postion over Time for Different Spring Preload Torque Values");
%xlabel("Time(s)");
%ylabel("Throttle Position (%)");
%hold off;
fileName = join(['simulationData2_',string(dutyCyclePWM),'.mat'],"")
save(fileName,'simulationData','inputTimeData');