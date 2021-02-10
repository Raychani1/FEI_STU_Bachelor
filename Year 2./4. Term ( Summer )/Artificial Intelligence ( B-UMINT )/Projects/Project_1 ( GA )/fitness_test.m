function [Fit] = fitness_test(Pop)
    [lpop,lstring]=size(Pop);
    start=[Pop(1,1),Pop(1,2)];
    stop=[Pop(1,end-1),Pop(1,end)];
    
    for i=1:lpop
      G=Pop(i,:);
      
      Fit(i)=0;	
      collision=collision_check(start,stop,G);
      
      if collision>0
            Fit(i)= Fit(i)+(1000000);
      end
      
      for j=1:2:lstring-2   
        Fit(i)=Fit(i)+sqrt((G(j)-G(j+2))^2+(G(j+1)-G(j+3))^2);
      end
      
    end
end

