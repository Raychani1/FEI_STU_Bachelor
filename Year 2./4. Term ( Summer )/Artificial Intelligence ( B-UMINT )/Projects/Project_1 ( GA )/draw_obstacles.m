function [] = draw_obstacles(start,stop)
[L,U,C]=calculate_obstacles(start,stop);
plot(L(:,1) , L(:,2),'r');hold on;
plot(U(:,1) , U(:,2),'r');hold on;
plot(C(:,1) , C(:,2),'r');hold on;
end

