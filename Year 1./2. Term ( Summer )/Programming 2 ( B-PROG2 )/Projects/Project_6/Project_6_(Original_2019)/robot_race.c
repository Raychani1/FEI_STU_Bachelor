#include <stdio.h>
#include "robot_race.h"
#include <stdlib.h>
#include <time.h>


// POPIS:
// Funkcia 'initTrack' inicializuje trat pred zavodom.
// Nahodne sa vygeneruju prekazky na trati 'track'.
// Pocet prekazok ako aj algoritmus generovania prekazok
// si urcite sami.
// VSTUP:
//      * track - smernik na zavodnu trat
// VYSTUP:
//      * funkcia nic nevrati



void initTrack(Track* track)
{
    srand(time(NULL));



    for (int j = 0; j < track->t_vyska; j++)

    {
        track->trat[j][0] = '|';
        for (int i = 1; i < track->t_sirka; i++)
        {


            track->trat[j][i] = ' ';

        }
        track->trat[j][track->t_sirka] = '|';
    }
    for (int i = 0; i < track->poc_prek; i++)
    {

        int x = rand() % (track->t_sirka - 2) + ROBOT_SPEED;
        int y = rand() % (track->t_vyska) + 1;
        int p_s = rand() % (track->t_sirka - x) + 1;
        int p_v = rand() % (5) + ROBOT_SPEED;
        Obstacle prekazka = { x,y,p_s,p_v };

        for (int i = 0; i < p_v; i++)
        {
            for (int j = 0;j < p_s; j++)
            {
                track->trat[y+i][x + j] = 177;
            }
        }
    }

    /*
    for (int j=0; j<track->t_vyska;j++)
    {

        track->trat[j][0] = '|';
        for (int i = 1; i < track->t_sirka; i++)
        {

        track->trat[j][i] = ' ';

        }
        track->trat[j][track->t_sirka] = '|';
    }
    //*/
    /*
    for (int j = 0; j < track->t_vyska; j++)
    {

        track->trat[j][0] = '|';
        for (int i = 1; i < track->t_sirka; i++)
        {
            for (int k = 0; k < track->poc_prek; k++)
            {
                if (track->prekazky[k].pr_x == i && track->prekazky[k].pr_y == j)
                {
                    track->trat[j][i] = 177;
                    for (i = track->prekazky[k].pr_x; i < track->prekazky[k].p_sirka; i++)
                    {
                        track->trat[j][i] = 177;

                    }
                    for (i = track->prekazky[k].p_sirka; i < track->t_sirka; i++)
                    {
                        track->trat[j][i] = ' ';

                    }

                }
                if (track->prekazky[k].pr_y <= j && i == track->prekazky[k].pr_x)
                {
                    for (i = track->prekazky[k].pr_x; i < track->prekazky[k].p_sirka; i++)
                    {
                        track->trat[j][i] = 177;

                    }
                    for (i = track->prekazky[k].p_sirka; i < track->t_sirka; i++)
                    {
                        track->trat[j][i] = ' ';

                    }
                    if (track->prekazky[k].p_vyska == j)
                    {
                        break;
                    }
                }


            }

                track->trat[j][i] = ' ';

        }
        track->trat[j][track->t_sirka] = '|';
    }*/
}

// POPIS:
// Funkcia 'initRobots' inicializuje robotov pred zavodom.
// Robotom (ich pocet je 'n') v poli 'robots' sa nastavia suradnice tak,
// aby stali na starte trate. Smer robotov bude nastaveny tak, aby
// smerovali rovno do ciela (smer nadol). Predvolena rychlost robota bude
// urcena konstantou 'ROBOT_SPEED' z robot_race.h.
// VSTUP:
//      * robots - pole s robotmi
//      * n - dlzka pola 'robots'
//      * track - smernik na zavodnu trat
// VYSTUP:
//      * funkcia nic nevrati
void initRobots(Robot robots[], int n, Track* track)
{

    int x = n + 1;
    for (int i = 0; i < n; i++)
    {
        char name_c = 97 + i;
        Robot rob_o;
        rob_o.rob_x = ((i + 1)*(track->t_sirka / x));
        rob_o.rob_y = 0;
        rob_o.rychlost = ROBOT_SPEED;
        rob_o.smer = 2;
        rob_o.name = name_c;
        robots[i] = rob_o;
        robots[i] = rob_o;
        track->trat[rob_o.rob_y][rob_o.rob_x] =robots[i].name;
    }
}
// POPIS:
// Funkcia 'print' vypise aktualny stav trate do konzoly. Vypisu sa
// pozicie robotov, okraje trate a prekazky.
// VSTUP:
//      * robots - pole s robotmi
//      * n - dlzka pola 'robots'
//      * track - smernik na zavodnu trat
// VYSTUP:
//      * funkcia nic nevrati
void print(Robot robots[], int n, Track* track)
{
    CLEAR_SCREEN();
    printf("\tSTART\n");
    for (int j=0; j<track->t_vyska;j++)
    {
        for (int i = 0; i <=track->t_sirka; i++)
        {
            printf("%c", track->trat[j][i]);
        }
        printf("\n");
    }
    printf("\t CIEL\n");

}
// POPIS:
// Funkcia 'updateRobotPosition' aktualizuje poziciu robota
// (t.j. robot sa pohne z jeho starej pozicie v jeho aktualnom
// smere a aktualnou rychlostou).
// VSTUP:
//      * robot - smernik na robota, ktoreho poziciu ideme aktualizovat
// VYSTUP:
//      * funkcia nic nevrati

void updateRobotPosition(Robot* robot, Track* track)
{
    if (robot->smer == 2)
    {
        track->trat[robot->rob_y][robot->rob_x] = '.';
        robot->rob_y = robot->rob_y + ROBOT_SPEED;
        track->trat[robot->rob_y][robot->rob_x] = robot->name;
    }
    if (robot->smer == 4)
    {
        track->trat[robot->rob_y][robot->rob_x] = '.';
        robot->rob_x = robot->rob_x - ROBOT_SPEED;
        track->trat[robot->rob_y][robot->rob_x] = robot->name;
    }
    if (robot->smer == 6)
    {
        track->trat[robot->rob_y][robot->rob_x] = '.';
        robot->rob_x = robot->rob_x + ROBOT_SPEED;
        track->trat[robot->rob_y][robot->rob_x] = robot->name;
    }
}



// POPIS:
// Funkcia 'updateRobotDirection' aktualizuje smer robota a to tak,
// aby sa vyriesila kolizna situacia s hranicou zavodnej trate
// alebo s prekazkou (to zavisi od parametra 'obstacle_id').
// VSTUP:
//      * robot - smernik na robota, ktory je v koliznej situacii
//      * track - smernik na zavodnu trat
//      * obstacle_id - identifikator koliznej situacie
// VYSTUP:
//      * funkcia nic nevracia

void updateRobotDirection(Robot* robot, Track* track, int obstacle_id)
{
    if (obstacle_id == 0)
    {
        robot->smer = 4;
    }
    if (obstacle_id == 1)
    {
        robot->smer = 4;
    }
    if (obstacle_id == -1)
    {
        robot->smer = 6;
    }
    if (obstacle_id == -2)
    {
        robot->smer = 2;
    }
}




// POPIS:
// Funkcia 'isCollision' zisti, ci sa robot moze zo svojej aktualnej pozicie
// pohnut aktualnym smerom a aktualnou rychlostou alebo dochadza ku kolizii
// (prekazka alebo hranica trate).
// VSTUP:
//      * robot - smernik na robota
//      * track - smernik na zavodnu trat
// VYSTUP:
//      * vrati -2: pohyb robota bude platny
//      * vrati -1: pohyb sposobi koliziu s hranicou trate
//      * vrati 0...n: pohyb robota sposobi koliziu s 'i'-tou prekazkou v poli prekazok



int isCollision(Robot* robot, Track* track)
{
    if (robot->smer == 4)
    {
        if (track->trat[robot->rob_y][robot->rob_x - ROBOT_SPEED] == '|')
        {
            return -1;
        }
    }
    if (robot->smer == 6)
    {
        if (track->trat[robot->rob_y][robot->rob_x + ROBOT_SPEED] == '|')
        {
            return 1;
        }
    }
    else
    {

        if (track->trat[robot->rob_y + ROBOT_SPEED][robot->rob_x] == ' ')
        {
            return -2;
        }
        if (track->trat[robot->rob_y + ROBOT_SPEED][robot->rob_x] == 177)
        {
            return 0;
        }
    }
}
