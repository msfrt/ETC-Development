%clear all
close all
%open_system('etb_Model_Sweep');
Simulink.sdi.clear;
dutyCyclePWM = 30;
springPreload = 780;
springConst = 300;
for i=1:10
    for a=1:10
        modelNum = (i-1)*10 + a;
        springConstValue = 100+(20*(i));
        springPreloadValue = 650+(20*a);
        simIn(modelNum) = Simulink.SimulationInput('etb_Model_Sweep');
        simIn(modelNum) = simIn(modelNum).setVariable('springConst',springConstValue);
        simIn(modelNum) = simIn(modelNum).setVariable('springPreload',springPreloadValue);
    end
    %springPreloadValue = 480+(20*i);
    %simIn(i) = Simulink.SimulationInput('etb_Model_Sweep');
    %simIn(i) = simIn(i).setVariable('springPreload',springPreloadValue);
end
simOutputs = sim(simIn);
runIDs = Simulink.sdi.getAllRunIDs();
figure(1);
hold on;
%legendText = single.empty(0,length(runIDs));
for i = 1:length(runIDs)
    Run = Simulink.sdi.getRun(runIDs(i));
    signal = getSignalByIndex(Run,6);
    a= signal.Values();
    plot(a);
    legendText(i)= string(i);
end
%t3(2313:2704) = t3(2313:2074) ;
plot((t3(2314:2703)- t3(2314)), ETC_throttlePosition1_pct_t3(2314:2703));
legend(legendText);
title("Percentage of Throttle Postion over Time for Different Spring Preload Torque Values");
xlabel("Time(s)");
ylabel("Throttle Position (%)");
hold off;