clc;
clear ;
close all;

[start,stop,dots]= coord_dots_input();

space=[start(1) start(2) start(1)*ones(1,dots) start(2)*ones(1,dots) stop(1) stop(2);
        start(1) start(2) stop(1)*ones(1,dots) stop(2)*ones(1,dots) stop(1) stop(2)];
Amp=[0,0,50*ones(1,dots),50*ones(1,dots),0,0];
num_of_gen = 12000;

figure(1);
draw_obstacles(start,stop);

for j = 1:10
population = genrpop(50,space);

graph=zeros(1,num_of_gen);

    for i = 1:num_of_gen

    fitness=fitness_test(population);

    best=selbest(population,fitness,1);
    graph(i)=fitness_test(best);
    figure(1);
    [a,b]=display_indiv(best);

    best15 = selbest(population,fitness,[8,4,3]);
    work = seltourn(population,fitness,35);

    work = crossov(work,1,0);
    work=mutx(work,0.1,space);
    %work=muta(work,0.1,Amp,space);
    population=[best15;work];

    pause(0.0001); 
    delete(a);
    delete(b);

    end
    [a,b]=display_indiv(best);
    if j == 1
        best_of_10 = best;
    else
        if fitness_test(best)<fitness_test(best_of_10)
            best_of_10=best;
        end
   
    end
    
    figure(2);
    plot(graph);hold on;
end

fit=fitness_test(best_of_10);
disp("Najlepšie riešenie má dåžku");
disp(fit)

figure(3)
draw_obstacles(start,stop);
display_indiv(best_of_10);