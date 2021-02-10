function [index_of_worst_individual] = selworst(Fvpop)
[fit,nix]=sort(Fvpop);
index_of_worst_individual=nix(end);
end

