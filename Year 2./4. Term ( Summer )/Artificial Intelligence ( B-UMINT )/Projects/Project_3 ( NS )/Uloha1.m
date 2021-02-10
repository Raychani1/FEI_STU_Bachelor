clear,clc 
close all;

load databody2
%nacitanie dat
A1 =data1(:,1).';
A2 =data1(:,2).';
A3 =data1(:,3).';
B1 =data2(:,1).';
B2 =data2(:,2).';
B3 =data2(:,3).';
C1 =data3(:,1).';
C2 =data3(:,2).';
C3 =data3(:,3).';
D1 =data4(:,1).';
D2 =data4(:,2).';
D3 =data4(:,3).';
E1 =data5(:,1).';
E2 =data5(:,2).';
E3 =data5(:,3).';
%zobrazenie dat

plot3(A1,A2,A3,'b+',B1,B2,B3,'co',C1,C2,C3,'g*',D1,D2,D3,'r*',E1,E2,E3,'mx');
axis([0 1 0 1 0 1]);
title('Data body');
xlabel('x');
ylabel('y');
zlabel('z');

%vstupné data pre NS
V1=[A1 B1 C1 D1 E1];
V2=[A2 B2 C2 D2 E2];
V3=[A3 B3 C3 D3 E3];
X=[V1;V2;V3];

nA=length(A1);
nB=length(B1);
nC=length(C1);
nD=length(D1);
nE=length(E1);

P=[ones(1,nA) zeros(1,nB) zeros(1,nC) zeros(1,nD) zeros(1,nE);zeros(1,nA) ones(1,nB) zeros(1,nC) zeros(1,nD) zeros(1,nE);zeros(1,nA) zeros(1,nB) ones(1,nC) zeros(1,nD) zeros(1,nE);zeros(1,nA) zeros(1,nB) zeros(1,nC) ones(1,nD) zeros(1,nE);zeros(1,nA) zeros(1,nB) zeros(1,nC) zeros(1,nD) ones(1,nE)];
all_conf = zeros(1,10);

net = patternnet(20); 
 
% Suma štvorcov odchýliek - nastavená úcelová funkcia
net.trainParam.goal = 1e-3;	    % Ukoncovacia podmienka na chybu SSE. 
net.trainParam.epochs = 100;  	% Max. pocet trénovacích cyklov.    
net.trainParam.show = 20;
net.trainParam.min_grad = 1e-6; % Ukoncovacia podmienka na min. gradient  

 
% vsetky data pouzite na trenovanie
net.divideFcn='dividerand';
net.divideParam.trainRatio=0.8;
net.divideParam.valRatio=0.0;
net.divideParam.testRatio=0.2;

[net,tr] = train(net,X,P);
 
Y=sim(net,X);
perf = perform(net,P,Y); %vycislenie chyby
classes = vec2ind(Y);%priradenie vstupov do tried 

plotperform(tr);
plotconfusion(P,Y);

%testovanie
figure(10)
 
view(3) %3d
plot3(A1,A2,A3,'b+',B1,B2,B3,'co',C1,C2,C3,'g*',D1,D2,D3,'r*',E1,E2,E3,'mx');
hold on
xtpom=[0.9]
ytpom=[0.9]
ztpom=[0.9]
plot3(xtpom,ytpom,ztpom,'.b')
hold off

% vytvorenie rovnomernej testovacej siete bodov 
[xTpom,yTpom,zTpom]=meshgrid(0:0.1:1,0:0.1:1,0:0.1:1);
xT2=xTpom(1:end);
yT2=yTpom(1:end);
zT2=zTpom(1:end);
X3=[xT2;yT2;zT2];
%sim vystupu
y3=sim(net,X3);
classes3 = vec2ind(y3);
figure(20)
view(3)
hold on
%plot3(X3(:,1),X3(:,2),X3(:,3))
retcolor='bcgrm';
plot3(A1,A2,A3,'b+')
plot3(B1,B2,B3,'co')
plot3(C1,C2,C3,'g*')
plot3(D1,D2,D3,'r*')
plot3(E1,E2,E3,'mx')


points = [0.9000 0.1000 0.9000
      0.5000 0.7000 0.1000
      0.2000 0.8000 0.6000
      0.9000 0.2000 0.3000
      1.0000 1.0000 1.0000];

net(points')
classes2 = vec2ind(net(points'))

class1='bd';
class2='cd';
class3='gd';
class4='rd';
class5='md';

for i=1:5
    switch(classes2(i))
        case 1
            plot3(points(i,1),points(i,2),points(i,3),class1);hold on;
        case 2
            plot3(points(i,1),points(i,2),points(i,3),class2);hold on;
        case 3
            plot3(points(i,1),points(i,2),points(i,3),class3);hold on;
        case 4
            plot3(points(i,1),points(i,2),points(i,3),class4);hold on;
        case 5
            plot3(points(i,1),points(i,2),points(i,3),class5);hold on;
    end
end

