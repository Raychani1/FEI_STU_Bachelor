% Aplikacia rozmiestnovania distribucnych centier na zaklade umiestnenia spotrebitelov
% pomocou Kohonenovej siete

close all;
clear, clc;

% Screensize = [1 1 sirka vyska]
rozl_displeja = get(0,'ScreenSize');
 
% nacitanie mapy do premennej
obrazok = imread('mapa.jpg');
velkost_obr = size(obrazok);
    
% Nastavi rozmery okna s ohladom na velkost obrazka
sirka = rozl_displeja(3)-100;
vyska = rozl_displeja(4)-200;
if (vyska-50) > velkost_obr(1)
    vyska = velkost_obr(1)+50;
end
if (sirka-100) > velkost_obr(2)
    sirka = velkost_obr(2)+100;
end
        
% Vytvorenie noveho okna
% nastavenie okna ('Position', [zlava zospodu sirka vyska])
f = figure('MenuBar','none','Name','Kohonenova neurÛnov· sieù','NumberTitle','off','Position',[100 rozl_displeja(4)-vyska-100 sirka vyska],...
           'doublebuffer','on','Color',[0.847 0.8745 0.9176]);
           
Axes = axes('ButtonDownFcn', @ButtonDown,'Position',[0.05 0.05 0.9 0.9],'XLim',[0,1],'YLim',[0,1]);
        
% nacitanie obrazka mapy
image(obrazok,'ButtonDownFcn', @ButtonDown);
axis off;
axis image;
hold on;
        
% nacitanie suradnic miest
load bodymapa1 
        
Points = line('XData',x,'YData',y,'LineStyle','None','Marker','o','MarkerEdgeColor','k','MarkerFaceColor','b','MarkerSize',5);  
hold on;
 
% definovanie rozmeru siete
 
riadky = 2;

stlpce = 3;

% permutacia cisel od 1 po dlzku pola
permutacia = randperm(length(x));
x = x( permutacia );           % Dolezite je zamiesat vstupne data
y = y( permutacia );           % aby sa mriezka neuronov rozprestierala rovnomerne
    
% Nahodna inicializacia vah
nahod=ceil(rand(stlpce*riadky,1)*length(x));

g=1;
for j=1:stlpce,
    for i=1:riadky,
        w1(i,j)=x(nahod(g,1),1);    % w1, w2 - v·hy neurÛnov
        w2(i,j)=y(nahod(g,1),1);
        g=g+1;
    end
end

% vykreslenie pozicii neuronov
h_neurony = plot(w1,w2,'o','MarkerEdgeColor','k','MarkerFaceColor','r','MarkerSize',8);

counter = 10;

gama1 = 0.8;      % zaciatocny krok ucenia

r1 = 4;           % polomer susedtsva

h1 = 1;           % vyska funkcie susedstva 

 for i=1:stlpce
    x_pom=w1(:,i);
    y_pom=w2(:,i);
    line(x_pom,y_pom);
end

for i=1:riadky
    x_pom=w1(i,:);
    y_pom=w2(i,:);
    line(x_pom,y_pom);
end

f = figure('MenuBar','none','Name','TrÈnovanie','NumberTitle','off','Position',[100 rozl_displeja(4)-vyska-100 sirka vyska],...
           'doublebuffer','on','Color',[0.847 0.8745 0.9176]);
           
Axes = axes('ButtonDownFcn', @ButtonDown,'Position',[0.05 0.05 0.9 0.9],'XLim',[0,1],'YLim',[0,1]);     

for p=1:counter              %zaciatok zadanych cyklov ucenia
    gama =exp((gama1)/p)-1;      %vypocet uciaceho sa parametra
    h=exp((-h1+1)/p);      %vypocet vysky adapt·cie
    r=r1*exp(-p);            %vypocet polomeru priestoroveho susedstva

    % prechadzam jednotlive mer. body
    for k = 1:length(x)
        out = (w1-x(k)).^2 + (w2-y(k)).^2;  %vypocet vzdialenosti neuronov od mer. bodu
        vitaz = out(1,1);        %pociatocny vitaz
        
        vit_x=1;
        vit_y=1;

        for j=1:stlpce             %hladanie vitaza prejdenim vsetkych hodnot
            for i=1:riadky
                if out(i,j)<vitaz    %hladanie minima
                    vitaz = out(i,j);
                    vit_x=i;
                    vit_y=j;
                end
                out(i,j)=0;       %vsetkych ostatnych nastavim na nulu
            end
        end

        out(vit_x,vit_y)=1;     %vitaza nastavim na jednotku

        %Nastava zmena vah k vitazovi
        for i=1:riadky
            for j=1:stlpce
                d=(vit_x-i).^2 + (vit_y-j).^2;                  % vzdialenost neuronu od vitazneho neuronu
                lambda = h * exp(-d/r);                         % urcenie lambdy
                w1(i,j)=w1(i,j)+gama*lambda*(x(k)-w1(i,j));     % zmena vah
                w2(i,j)=w2(i,j)+gama*lambda*(y(k)-w2(i,j));     % zmena vah
            end
        end

        figure(2)     
        cla    %Vykreslenie priebehu ucenia v kazdom k kroku

        image(obrazok,'ButtonDownFcn', @ButtonDown);
        axis off;
        axis image;
        hold on
        h_neurony = plot(w1,w2,'o','MarkerEdgeColor','k','MarkerFaceColor','r','MarkerSize',8);
        line('XData',x,'YData',y,'LineStyle','None','Marker','o','MarkerEdgeColor','k','MarkerFaceColor','b','MarkerSize',5);
        hold on;

        for i=1:riadky
            x_pom = w1(i,:);
            y_pom = w2(i,:);
            line(x_pom,y_pom);
        end

        for i=1:stlpce
            x_pom = w1(:,i);
            y_pom = w2(:,i);
            line(x_pom,y_pom);
        end

        hold on;

        shg      %show graph

        pause(0.01);
    end
end           % koniec celeho ucenia

skupiny=roztried(w1,w2,x,y,riadky,stlpce);

sklady = zeros(riadky,stlpce);
vzdialenost = zeros(riadky,stlpce);
priemerna_vzdial = zeros(riadky,stlpce); 

colors = ['#FFFF00';'#FF00FF';'#00FFFF';'#FF0000';'#00FF00';'#0000FF';'#FFFFFF';'#000000';'#7E2F8E';'#D95319']; 

f = figure('MenuBar','none','Name','Rieöenie','NumberTitle','off','Position',[100 rozl_displeja(4)-vyska-100 sirka vyska],...
               'doublebuffer','on','Color',[0.847 0.8745 0.9176]);
           
Axes = axes('ButtonDownFcn', @ButtonDown,'Position',[0.05 0.05 0.9 0.9],'XLim',[0,1],'YLim',[0,1]);
        
image(obrazok,'ButtonDownFcn', @ButtonDown);
axis off;
axis image;
hold on   

sklad1_vdzial = [];
sklad2_vdzial = [];
sklad3_vdzial = [];
sklad4_vdzial = [];
sklad5_vdzial = [];
sklad6_vdzial = [];
sklad7_vdzial = [];
sklad8_vdzial = [];
sklad9_vdzial = [];
sklad10_vdzial = [];

k=0;
for i = 1: riadky
    for j = 1: stlpce
        k=k+1;
        plot(w1(i,j),w2(i,j),'o','MarkerEdgeColor','k','MarkerFaceColor',colors(k,:),'MarkerSize',8);
        a = [];
        m=1;
        for f=1:59
            if(skupiny(f,1)==i && skupiny(f,2)==j)
                sklady(i,j) = sklady(i,j) + 1;
                a(end+1) = sqrt((x(f)-w1(i,j)).^2 + (y(f)-w2(i,j)).^2);
                line('XData',x(f),'YData',y(f),'LineStyle','None','Marker','o','MarkerEdgeColor','k','MarkerFaceColor',colors(k,:),'MarkerSize',5);
                m = m+1;
            end 
        end
        switch(k)
            case 1
                sklad1_vdzial = a;
            case 2
                sklad2_vdzial = a;
            case 3
               sklad3_vdzial = a;
            case 4
                sklad4_vdzial = a;
            case 5
                 sklad5_vdzial = a;
            case 6
                sklad6_vdzial = a;
            case 7
                sklad7_vdzial = a;
            case 8
                sklad8_vdzial = a;
            case 9
                sklad9_vdzial = a;
            case 10
                 sklad10_vdzial = a;
        end
    end
end

k=1;
for i = 1 : riadky
    for j = 1: stlpce
        disp(['Sklad ',num2str(k)]);
        disp(sklady(i,j));
        disp(['Suma vzdial. ',num2str(k)]);
        switch(k)
            case 1
                disp(sum(sklad1_vdzial));
                disp(['Priemern· vzdial. ',num2str(k)]);
                disp(mean(sklad1_vdzial));
            case 2
                disp(sum(sklad2_vdzial));
                disp(['Priemern· vzdial. ',num2str(k)]);
                disp(mean(sklad2_vdzial));
            case 3
               disp(sum(sklad3_vdzial));
               disp(['Priemern· vzdial. ',num2str(k)]);
               disp(mean(sklad3_vdzial));
            case 4
                disp(sum(sklad4_vdzial));
                disp(['Priemern· vzdial. ',num2str(k)]);
                disp(mean(sklad4_vdzial));
            case 5
                 disp(sum(sklad5_vdzial));
                 disp(['Priemern· vzdial. ',num2str(k)]);
                 disp(mean(sklad5_vdzial));
            case 6
                disp(sum(sklad6_vdzial));
                disp(['Priemern· vzdial. ',num2str(k)]);
                disp(mean(sklad6_vdzial));
            case 7
                disp(sum(sklad7_vdzial));
                disp(['Priemern· vzdial. ',num2str(k)]);
                disp(mean(sklad7_vdzial));
            case 8
                disp(sum(sklad8_vdzial));
                disp(['Priemern· vzdial. ',num2str(k)]);
                disp(mean(sklad8_vdzial));
            case 9
                disp(sum(sklad9_vdzial));
                disp(['Priemern· vzdial. ',num2str(k)]);
                disp(mean(sklad9_vdzial));
            case 10
                 disp(sum(sklad10_vdzial));
                 disp(['Priemern· vzdial. ',num2str(k)]);
                 disp(mean(sklad10_vdzial));
        end
        k = k + 1;
    end
end