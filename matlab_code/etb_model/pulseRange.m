close all
index=1;
for i= 2:length(ETC_motorAPWM_t2)
       if (ETC_motorAPWM_t2(i)- ETC_motorAPWM_t2(i-1) > 0)
           pulseCord(index,1) = i;
           pulseCord(index,3)= ETC_motorAPWM_t2(i);
       elseif (ETC_motorAPWM_t2(i)- ETC_motorAPWM_t2(i-1) < 0)
           pulseCord(index,2) = i;
           index = index + 1;
       end
end

figure(1);
hold on;
for i = 1:length(pulseCord)
    plot(t3(pulseCord(i,1):pulseCord(i,2))-t3(pulseCord(i,1)),ETC_throttlePosition1_pct_t3(pulseCord(i,1):pulseCord(i,2)))
end
legend(string(pulseCord(:,3)));
hold off;
