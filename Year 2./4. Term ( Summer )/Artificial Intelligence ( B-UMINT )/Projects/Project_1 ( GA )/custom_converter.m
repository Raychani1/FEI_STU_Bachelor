function [ a ] = custom_converter(indiv)
a=zeros(numel(indiv)/2,2);
j=1;
for i=1:2:numel(indiv)-1
    a(j,1)=indiv(i);
    a(j,2)=indiv(i+1);
    j=j+1;
end;

