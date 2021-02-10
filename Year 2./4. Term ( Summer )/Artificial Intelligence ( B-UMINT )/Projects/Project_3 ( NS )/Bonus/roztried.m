% vypise do matice pod seba dvojce suradnic(indexov v matici w1(w2)) 

% najblizsieho neuronu pre kazdy bod vstupnych dat

function[vysledok]=roztried(w1,w2,x,y,riadky,stlpce)

    vysledok=[];                   % pozicie (v matici) najblizsich neuronov k bodom 

                                    % usporiadane podla poradia bodov v poli

    for m=1:length(x)               % cez vsetky vstupne body

        min_vzdial=1000;

        neuron=[];

        for i=1: riadky       % x-suradnice neuronov (riadky)  

            for j=1:stlpce      % x-suradnice neuronov (stlpce)   size(w1,1)

                vzdial= sqrt((w1(i,j)-x(m,1))^2 + (w2(i,j)-y(m,1))^2);      % vyrata vzdialenost pre konkretny neuron
                if (vzdial <= min_vzdial)

                    min_vzdial=vzdial;

                    neuron=[i j];

                end

            end

        end

        vysledok=[vysledok; neuron];

    end

