function [Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9,graph,values] = GA(Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9,Space,i,graph)
    [Island9,graph,best_one9]=GA_lower(Island9,Space,graph,9,i);
    [Island8,graph,best_one8]=GA_lower(Island8,Space,graph,8,i);
    [Island7,graph,best_one7]=GA_lower(Island7,Space,graph,7,i);
    [Island6,graph,best_one6]=GA_lower(Island6,Space,graph,6,i);
    [Island5,graph,best_one5]=GA_higher(Island5,Space,graph,5,i);
    [Island4,graph,best_one4]=GA_higher(Island4,Space,graph,4,i);
    [Island3,graph,best_one3]=GA_higher(Island3,Space,graph,3,i);
    [Island2,graph,best_one2]=GA_higher(Island2,Space,graph,2,i);
    [Island1,graph,best_one1]=GA_top(Island1,Space,graph,1,i);
    [graph,values] = best_individual(best_one1,best_one2,best_one3,best_one4,best_one5,best_one6,best_one7,best_one8,best_one9,graph,10,i);
end

