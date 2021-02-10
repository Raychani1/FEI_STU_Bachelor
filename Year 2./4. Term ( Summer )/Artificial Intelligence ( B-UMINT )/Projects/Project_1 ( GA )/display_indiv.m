function [a,b] = display_indiv(individual)
individual=custom_converter(individual);
a=plot(individual(:,1),individual(:,2),'ro');hold on;
b=plot(individual(:,1),individual(:,2),'b');
end


