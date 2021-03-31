clear all
close all
%open_system('etb_Model_Sweep');
Simulink.sdi.clear;
dutyCyclePWM = 40;
springPreload = 780;
springConst = 300;
for i=1:16
    dutyCycle = 19+i;
    simIn(i) = Simulink.SimulationInput('etb_Model_Sweep');
    simIn(i) = simIn(i).setVariable('dutyCyclePWM',dutyCycle);
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
    legendText(i)= string(19+i);
end
legend(legendText);
title("Percentage of Throttle Postion over Time for Different PWM Values");
xlabel("Time(s)");
ylabel("Throttle Position (%)");
hold off;