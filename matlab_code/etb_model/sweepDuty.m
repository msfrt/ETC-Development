clear all
%open_system('etb_Model');
Simulink.sdi.clear;
sweep = 40;
for i=1:16
    dutyCycle = 19+i;
    simIn(i) = Simulink.SimulationInput('etb_Model');
    simIn(i) = simIn(i).setVariable('sweep',dutyCycle);
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
hold off;