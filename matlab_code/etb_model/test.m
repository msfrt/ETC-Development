close all
i=3;
figure();
hold on;
legend on;
plot(t3(pulseCord(i,1):pulseCord(i,2))-t3(pulseCord(i,1)),ETC_throttlePosition1_pct_t3(pulseCord(i,1):pulseCord(i,2)),'DisplayName','Real')
plot(Correct,'DisplayName','Correct')
plot(Incorrect,'DisplayName','Incorrect')