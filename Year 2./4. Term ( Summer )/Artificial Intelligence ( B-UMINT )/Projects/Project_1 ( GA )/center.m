function [x,y,s] = center(start,stop)
    s=(stop(2)-start(2))/5;
    x=start(1)+abs(((stop(1))-(start(1)))/2-(1.75*s));
    y=start(2)+abs(((stop(2))-(start(2)))/2+(s/2));
    
end

