function [destination] = migration(destination,replacement) 
    n=selworst(fitness_funkcia(destination));
    destination(n,:)=replacement;
end