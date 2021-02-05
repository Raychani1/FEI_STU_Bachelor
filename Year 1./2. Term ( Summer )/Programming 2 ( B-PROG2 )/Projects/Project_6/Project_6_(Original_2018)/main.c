#include <stdio.h>
#include "robot_race.h"

int main(int argc, char* argv[]){
    int sirka, vyska, pocet_prek,pocet_robot;
    printf("Zadajte sirku trate: ");
    scanf("%d", &sirka);
    printf("Zadajte vysku trate: ");
    scanf("%d", &vyska);
    printf("Zadajte pocet prekazok: ");
    scanf("%d", &pocet_prek);
    printf("Zadajte pocet robotov: ");
    scanf("%d", &pocet_robot);
    Track t = { sirka,vyska,pocet_prek };
    char trat[MAX_TRACK_HEIGHT][MAX_TRACK_WIDTH];
    Robot robots[MAX_ROBOTS];


    initTrack(&t);
    initRobots(robots, pocet_robot, &t);
    print(robots, pocet_robot, &t);

    do {
        SLEEP(1000);
        //getchar();
        for (int i = 0; i < pocet_robot; i++) {
            int colid = isCollision(&robots[i], &t);
            // Pre kazdeho robota v poli sa zopakuju kroky 'a' a 'b':
            // a) kontrola, ci pohyb i-teho robota nesposobi koliziu
            // ... zavolanim funkcie isCollision()
            if (colid != -2)
            {
                updateRobotDirection(&robots[i], &t, colid);
            }
            else
            {
                updateRobotPosition(&robots[i],&t);
            }
            print(robots, pocet_robot, &t);
        }
    } while (1);


    return 0;
}
