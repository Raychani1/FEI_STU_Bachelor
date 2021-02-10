function [Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9] = migration_between_islands(Island1,Island2,Island3,Island4,Island5,Island6,Island7,Island8,Island9)

	fitness2 = fitness_funkcia(Island2);
	replacement=selbest(Island2,fitness2,1);
	Island1=migration(Island1,replacement);
        
	fitness3 = fitness_funkcia(Island3);
	replacement=selbest(Island3,fitness3,1);
	Island1=migration(Island1,replacement);
                
	fitness4 = fitness_funkcia(Island4);
	replacement=selbest(Island4,fitness4,1);
	Island1=migration(Island1,replacement);
        
	fitness5 = fitness_funkcia(Island5);
	replacement=selbest(Island5,fitness5,1);
	Island1=migration(Island1,replacement);
        
	fitness6 = fitness_funkcia(Island6);
	replacement=selbest(Island6,fitness6,1);
	Island2=migration(Island2,replacement);

	fitness7 = fitness_funkcia(Island7);
	replacement=selbest(Island7,fitness7,1);
	Island3=migration(Island3,replacement);
        
	fitness8 = fitness_funkcia(Island8);
	replacement=selbest(Island8,fitness8,1);
	Island4=migration(Island4,replacement);
        
	fitness9 = fitness_funkcia(Island9);
	replacement=selbest(Island9,fitness9,1);
    Island5=migration(Island5,replacement);
     
end

