function [L,U,C] = calculate_obstacles(start,stop)
[x,y,s]=center(start,stop);
L=[x y;x y-s;x+s y-s];
x=x+s+s/4;
U= [x y;x y-s; x+s y-s; x+s y];
x=x+s+s/4;
C= [x+s y-s/5;x+s y;x y;x y-s;x+s y-s;x+s y-4*s/5];

end

