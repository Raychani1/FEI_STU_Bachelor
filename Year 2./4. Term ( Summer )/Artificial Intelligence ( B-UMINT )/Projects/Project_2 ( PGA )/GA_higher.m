function [Island,graph,best_one] = GA_higher(Island,Space,graph,j,i)
    fitness=fitness_funkcia(Island);
    best = selbest(Island,fitness,[25,20,15]);
    best_one = selbest(Island,fitness,1);
    graph(j,i)=fitness_funkcia(best_one);
    work = selsus(Island,fitness,40);
    work = crossov(work,1,0);
    work = mutx(work,0.1,Space);
    Amp = ones(1,7);
    work = muta(work,0.1,Amp,Space);
    Island = [best;work];  
end