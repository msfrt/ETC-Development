clear;
close all;
Simulink.sdi.clear;

springPreload = 800;
springConst = 200;
motorPosGainI = 0;

motorPosGainP = 2000;
motorVelGainP = 200;
motorVelGainI = 2500;

motorVelGainFeedback = 200;

motorPosCmd = 60;

motorPosGainP = 1000:500:2500;
motorVelGainP = 200:200:1000;
%motorVelGainI = 1500:500:2500;
%motorVelGainFeedback = 50:50:600;

var1size = length(motorPosGainP);
var2size = length(motorVelGainP);
var3size = length(motorVelGainI);
var4size = length(motorVelGainFeedback);

i = 1;
for idx1=1:var1size
    for idx2=1:var2size
        for idx3=1:var3size
            for idx4=1:var4size
        
                simIn(i) = Simulink.SimulationInput('etb_positionControlModel');
                simIn(i) = simIn(i).setVariable('motorPosGainP',motorPosGainP(idx1));
                simIn(i) = simIn(i).setVariable('motorVelGainP',motorVelGainP(idx2));
                simIn(i) = simIn(i).setVariable('motorVelGainI',motorVelGainI(idx3));
                simIn(i) = simIn(i).setVariable('motorVelGainFeedback',motorVelGainFeedback(idx4));

                i = i+1;
            end
        end
    end
end

simOutputs = sim(simIn);
runIDs = Simulink.sdi.getAllRunIDs();
figure(1);
hold on;

%legendText = single.empty(0,length(runIDs));

yline(motorPosCmd);
legendText(1) = "motorPosCmd";

for i = 1:length(runIDs)
    Run = Simulink.sdi.getRun(runIDs(i));
    signal = getSignalByIndex(Run,6);
    a= signal.Values();
    plot(find(simOutputs(i).logsout, 'throttleBladePositionPercent').Values());  
    
    str1 = strcat("Run" ,string(num2str(i)));
    str2 = strcat("motorPosGainP:", string(num2str(getdatasamples(find(simOutputs(i).logsout, 'motorPosGainP').Values(),1))));
    str3 = strcat("motorVelGainP:", string(num2str(getdatasamples(find(simOutputs(i).logsout, 'motorVelGainP').Values(),1))));
    str4 = strcat("motorVelGainI:", string(num2str(getdatasamples(find(simOutputs(i).logsout, 'motorVelGainI').Values(),1))));
    str5 = strcat("motorVelGainFeedback:", string(num2str(getdatasamples(find(simOutputs(i).logsout, 'motorVelGainFeedback').Values(),1))));
    legendText(i+1) = strcat(str1, "   ", str2, "   ", str3, "   ", str4, "   ", str5);
end


legend(legendText);
title("Percentage of Throttle Postion over Time for Different Spring Preload Torque Values");
xlabel("Time(s)");
ylabel("Throttle Position (%)");
hold off;