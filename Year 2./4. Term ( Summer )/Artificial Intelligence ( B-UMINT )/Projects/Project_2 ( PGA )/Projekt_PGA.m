close all;
clc;

Space = [-10 * ones(1, 7);10 * ones(1,7)];
popsize = 100;

number_of_generations = 10000;
graph = zeros(10,number_of_generations);

Population=genrpop(popsize*9,Space);
Island1=Population(1:popsize,:);
Island2=Population(popsize+1:2*popsize,:);
Island3=Population(2*popsize+1:3*popsize,:);
Island4=Population(3*popsize+1:4*popsize,:);
Island5=Population(4*popsize+1:5*popsize,:);
Island6=Population(5*popsize+1:6*popsize,:);
Island7=Population(6*popsize+1:7*popsize,:);
Island8=Population(7*popsize+1:8*popsize,:);
Island9=Population(8*popsize+1:9*popsize,:);

values = zeros(1,7);

for i = 1 : number_of_generations
    [Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9,graph,values]= ...
        GA(Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9,Space,i,graph);
    if(mod(i,100)==0)
       [Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9] = ...
           migration_between_islands(Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9);
    end 
end

for i = 1:9
    figure(i);
    plot(graph(i,:));hold on;
    %title(['PGA - ',num2str(i),'.ostrov - Màtva pokuta']);
    %title(['PGA - ',num2str(i),'.ostrov - Stupòovitá pokuta']);
    title(['PGA - ',num2str(i),'.ostrov - Pokuta pod¾a miery porušenia']);
    ylabel('Fitness');
    xlabel('Generations');
end

for i = 1:9
    figure(10);
    plot(graph(i,:));hold on;
    %title('PGA - Všetky ostrovy - Màtva pokuta');
    %title('PGA - Všetky ostrovy - Stupòovitá pokuta');
    title('PGA - Všetky ostrovy - Pokuta pod¾a miery porušenia');
    ylabel('Fitness');
    xlabel('Generations');
end

figure(11);
plot(graph(10,:));hold on;
%title('PGA - Najlepší jedinec - Màtva pokuta');
%title('PGA - Najlepší jedinec - Stupòovitá pokuta');
title('PGA - Najlepší jedinec - Pokuta pod¾a miery porušenia');
ylabel('Fitness');
xlabel('Generations');


%disp('PGA - Màtva pokuta - Gény najlepšieho jedinca');
%disp('PGA - Stupòovitá pokuta - Gény najlepšieho jedinca');
disp('PGA - Pokuta pod¾a miery porušenia - Gény najlepšieho jedinca');

%%%%%%%%%%%%%%%%%%%%%GA - Dokumentácia strana 3%%%%%%%%%%%%%%%%%%%%%

% graph=zeros(1,number_of_generations);
% values = zeros(1,7);
% 
% for i = 1:10000
%     fitness=fitness_funkcia(Population);
%     best = selbest(Population,fitness,[20,15,10]); 
%     best_one = selbest(Population,fitness,1);
%     graph(i)=fitness_funkcia(best_one);
%     values=best_one;
%     work = selsus(Population,fitness,55);
%     work = crossov(work,1,0);
%     work = mutx(work,0.1,Space);
%     Amp = ones(1,7);
%     work = muta(work,0.1,Amp,Space);
%     Population=[best;work];
% end

% disp('Màtva pokuta');
% disp('Stupòovitá pokuta');
% disp('Pokuta pod¾a miery porušenia');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp(values);

disp('Funkèná hodnota najlepšieho jedinca')
disp(fitness_funkcia(values));


