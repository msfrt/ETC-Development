%clear all
close all
%open_system('etb_Model_Sweep');
Simulink.sdi.clear;
dutyCyclePWM = 25;
springPreload = 780;
springConst = 300;
for i=1:26
    springPreloadValue = 480+(20*i);
    simIn(i) = Simulink.SimulationInput('etb_Model_Sweep');
    simIn(i) = simIn(i).setVariable('springPreload',springPreloadValue);
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
    legendText(i)= string(480+(20*i));
end
plot((t3(437:826)- t3(437)), ETC_throttlePosition1_pct_t3(437:826));
legend(legendText);
title("Percentage of Throttle Postion over Time for Different Spring Preload Torque Values");
xlabel("Time(s)");
ylabel("Throttle Position (%)");
hold off;