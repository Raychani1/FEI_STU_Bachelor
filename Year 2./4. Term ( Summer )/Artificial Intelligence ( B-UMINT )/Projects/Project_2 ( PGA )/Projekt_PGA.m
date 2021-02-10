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
    %title(['PGA - ',num2str(i),'.ostrov - M�tva pokuta']);
    %title(['PGA - ',num2str(i),'.ostrov - Stup�ovit� pokuta']);
    title(['PGA - ',num2str(i),'.ostrov - Pokuta pod�a miery poru�enia']);
    ylabel('Fitness');
    xlabel('Generations');
end

for i = 1:9
    figure(10);
    plot(graph(i,:));hold on;
    %title('PGA - V�etky ostrovy - M�tva pokuta');
    %title('PGA - V�etky ostrovy - Stup�ovit� pokuta');
    title('PGA - V�etky ostrovy - Pokuta pod�a miery poru�enia');
    ylabel('Fitness');
    xlabel('Generations');
end

figure(11);
plot(graph(10,:));hold on;
%title('PGA - Najlep�� jedinec - M�tva pokuta');
%title('PGA - Najlep�� jedinec - Stup�ovit� pokuta');
title('PGA - Najlep�� jedinec - Pokuta pod�a miery poru�enia');
ylabel('Fitness');
xlabel('Generations');


%disp('PGA - M�tva pokuta - G�ny najlep�ieho jedinca');
%disp('PGA - Stup�ovit� pokuta - G�ny najlep�ieho jedinca');
disp('PGA - Pokuta pod�a miery poru�enia - G�ny najlep�ieho jedinca');

%%%%%%%%%%%%%%%%%%%%%GA - Dokument�cia strana 3%%%%%%%%%%%%%%%%%%%%%

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

% disp('M�tva pokuta');
% disp('Stup�ovit� pokuta');
% disp('Pokuta pod�a miery poru�enia');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp(values);

disp('Funk�n� hodnota najlep�ieho jedinca')
disp(fitness_funkcia(values));


