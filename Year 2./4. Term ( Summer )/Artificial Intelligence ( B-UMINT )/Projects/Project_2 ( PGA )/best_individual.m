function [graph,values] = best_individual(best_one1,best_one2,best_one3,best_one4,best_one5,best_one6,best_one7,best_one8,best_one9,graph,j,i)
    group_of_best_ones=[best_one1;best_one2;best_one3;best_one4;best_one5;best_one6;best_one7;best_one8;best_one9];
    
    fitness = fitness_funkcia(group_of_best_ones);
    best_of_all = selbest(group_of_best_ones,fitness,1);
    
    values = best_of_all;
    graph(j,i)=fitness_funkcia(best_of_all);
end