clc;
clear;
close all;

data = csvread('dataonly.txt');

% train_usp = zeros(1,10);
% test_usp = zeros(1,10);

% for j = 1:10
    t = data(:,20);
    target = zeros(size(t,1),2);    % do 2 skupin 
                                    % matiaca ziadanych hodnot 
    for i=1:size(t,1)
            target(i, t(i)+1)= 1;  
    end
    targets=target';

    inputs = data(:,1:19)';

    hiddenLayerSize = 40;

    net = patternnet(hiddenLayerSize);

    net.divideFcn = 'dividerand';

    net.divideParam.trainRatio =0.6;
    net.divideParam.valRatio  = 0.0;
    net.divideParam.testRatio = 0.4;

    net.trainParam.goal = 0.000001;
    net.trainParam.show = 20;
    net.trainParam.epochs = 600;  
    net.trainParam.min_grad = 1e-10;

    net.performFcn;

    [net,tr] = train (net,inputs,targets);
    
    outputs = net(inputs);
    figure
    plotconfusion(targets,outputs);
%     title(['Neural network (',num2str(j),')']);
    title('All confusion matrix');

    errors = gsubtract(targets,outputs);
    petrformance = perform (net, targets, outputs);

    outputTrain = net(inputs(:,tr.trainInd));
    targetTrain = targets(:,tr.trainInd);
    figure
    plotconfusion(targetTrain,outputTrain);

    title('Train confusion matrix');
%     title(['Train (',num2str(j),')']);
%     [c,cm] = confusion(targetTrain,outputTrain);
%     train_usp(j) = (1-c)*100;

    outputTest = net(inputs(:,tr.testInd));
    targetTest = targets(:,tr.testInd);
    figure
    plotconfusion(targetTest,outputTest);
    title('Test confusion matrix');
%     title(['Test (',num2str(j),')']);
%     [c,cm] = confusion(targetTest,outputTest);
%     test_usp(j) = (1-c)*100;
% end

% disp('==============DOSIAHNUT� HODNOTY==============');
% disp('Na tr�novac�ch d�tach:')
% disp(train_usp);
% disp('Na testovac�ch d�tach:')
% disp(test_usp);
% disp('=====================TRAIN====================');
% disp('Minim�lna �spe�nos� na tr�novac�ch d�tach :');
% disp(min(train_usp));
% disp('Maxim�lna �spe�nos� na tr�novac�ch d�tach :');
% disp(max(train_usp));
% disp('Priemern� �spe�nos� na tr�novac�ch d�tach :');
% disp(mean(train_usp));
% 
% disp('=====================TEST====================');
% 
% disp('Minim�lna �spe�nos� na testovac�ch d�tach :');
% disp(min(test_usp));
% disp('Maxim�lna �spe�nos� na testovac�ch d�tach :');
% disp(max(test_usp));
% disp('Priemern� �spe�nos� na testovac�ch d�tach :');
% disp(mean(test_usp));

disp('==================TESTOVANIE==================');
random =randi([1 1151],1,10);
for i = 1:10
    disp(['================= ',num2str(i),'. pacient =================']);
    prediction = net(inputs(:,random(i)))
    predicted_output = vec2ind(prediction)-1
    real_output = t(random(i))
end


