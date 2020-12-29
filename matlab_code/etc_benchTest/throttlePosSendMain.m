
% clc 
% clear

x1 = evalin( 'base', 'exist(''chData'',''var'') == 1' );
x2 = evalin( 'base', 'exist(''chNames'',''var'') == 1' );

if ~(x1 && x2)
    chData = darab2matlab();
    chNames = chData.Properties.VariableNames;
end

data = processData(chNames, chData);

set_param('throttlePosSend', 'EnablePacing', 'on')
output = sim('throttlePosSend','StartTime', num2str(data.tStart),'StopTime', num2str(data.tEnd),'FixedStep', num2str(data.tSample));
