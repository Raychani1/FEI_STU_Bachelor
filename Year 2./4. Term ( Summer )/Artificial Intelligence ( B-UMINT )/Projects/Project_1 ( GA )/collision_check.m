function [collision] = collision_check(start, stop,indiv)
[L,U,C]=calculate_obstacles(start, stop);
collision=0;
indiv=custom_converter(indiv);

for i=1:(numel(indiv)/2)-1
        x1 = indiv(i,1);
        y1 = indiv(i,2);
        x2 = indiv(i+1,1);
        y2 = indiv(i+1,2);
        
    for j=1:(numel(L)/2)-1
        x3=L(j,1);
        y3=L(j,2);
        x4=L(j+1,1);
        y4=L(j+1,2);

        [t,u]=calculate_t_and_u(x1,y1,x2,y2,x3,y3,x4,y4);
        
        if(t>=0 && t<=1 && u>=0 && u<=1)
                collision=collision+1;        
        end

    end
    
    for j=1:(numel(U)/2)-1
        x3=U(j,1);
        y3=U(j,2);
        x4=U(j+1,1);
        y4=U(j+1,2);
        
       [t,u]=calculate_t_and_u(x1,y1,x2,y2,x3,y3,x4,y4);
               
        if(t>=0 && t<=1 && u>=0 && u<=1)
                collision=collision+1;       
        end

    end

    for j=1:(numel(C)/2)-1
        x3=C(j,1);
        y3=C(j,2);
        x4=C(j+1,1);
        y4=C(j+1,2);
        
        [t,u]=calculate_t_and_u(x1,y1,x2,y2,x3,y3,x4,y4);
        
        if(t>=0 && t<=1 && u>=0 && u<=1)
                collision=collision+1;         
        end

     end
end
end

