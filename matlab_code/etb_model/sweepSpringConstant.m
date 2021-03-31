clear all
close all
%open_system('etb_Model_Sweep');
Simulink.sdi.clear;
dutyCyclePWM = 27;
springPreload = 780;
springConst = 300;
for i=1:26
    springPreloadValue = (20*(i-1));
    simIn(i) = Simulink.SimulationInput('etb_Model_Sweep');
    simIn(i) = simIn(i).setVariable('springConst',springPreloadValue);
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
    legendText(i)= string(20*(i-1));
end
legend(legendText);
title("Percentage of Throttle Postion over Time for Different Spring Constant Values");
xlabel("Time(s)");
ylabel("Throttle Position (%)");
hold off;