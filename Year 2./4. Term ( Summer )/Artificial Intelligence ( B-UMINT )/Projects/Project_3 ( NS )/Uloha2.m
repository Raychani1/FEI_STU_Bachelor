clc;
clear;
close all;

load datafun2;

net=fitnet(15);

net.divideFcn='divideind';      
net.divideParam.trainInd=indx_train;
net.divideParam.testInd=indx_test;

% Nastavenie parametrov trénovania
net.trainParam.goal = 1e-4;     
net.trainParam.show = 5;        

% Trénovanie NS
net=train(net,x,y);

% Simulácia vıstupu NS
outnetsim = sim(net,x);

% Vykreslenie priebehov
figure

xtrain = x(indx_train);
xtest = x(indx_test); 
ytrain = y(indx_train); 
ytest= y(indx_test);

ytrainnet = net(xtrain);
ytestnet = net(xtest);

plot(x,y,'b',xtrain,ytrainnet,'og',xtest,ytestnet,'*r'); hold on;
legend('Funkcia','Train','Test');

% SSE

disp('===============SSE===============')
% sse_network_matlab = sse(net,outnetsim,y)
sse_network = sum(power((outnetsim - y),2));
disp('SSE for network:');
disp(sse_network);

% sse_train_matlab=sse(net,ytrainnet,ytrain)
sse_train = sum(power((ytrainnet - ytrain),2));
disp('SSE for training data:');
disp(sse_train);

% sse_test_matlab=sse(net,ytestnet,ytest)
sse_test = sum(power((ytestnet - ytest),2));
disp('SSE for testing data:');
disp(sse_test);


% MAE

disp('===============MAE===============')
mae_network = max(abs(outnetsim - y));
disp('MAE for network:');
disp(mae_network);

mae_train = max(abs(ytrainnet - ytrain));
disp('MAE for training data:');
disp(mae_train);

mae_test = max(abs(ytestnet - ytest));
disp('MAE for testing data:');
disp(mae_test);


%MSE

disp('===============MSE===============')
% mse_network_matlab = mse(net,outnetsim,y)
mse_network = 1/numel(outnetsim)*sse_network;
disp('MSE for network:');
disp(mse_network);

% mse_train_matlab=mse(net,ytrainnet,ytrain)
mse_train = 1/numel(ytrain)*sse_train;
disp('MSE for training data:');
disp(mse_train);

% mse_test_matlab=mse(net,ytestnet,ytest)
mse_test = 1/numel(ytest)*sse_test;
disp('MSE for testing data:');
disp(mse_test);

