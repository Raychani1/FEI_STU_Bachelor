#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "steeplechase.h"

struct Runner {
    int runner_number;  // The runner's number
    int speed;          // The runner's speed at the moment ( cm/s )
    int max_speed;      // The runner's max speed
    int distance;       // Runner's distance from the starting line
    int tripped;        // The number of times the runner tripped on an obstacle
};

int increase_speed(int speed) {
    int new_speed = 0;                          // Variable so we do not user several returns.
    if (speed == 0) {                           // If the runner is starting to run at the start or after a trip.
        new_speed = rand() % 101 + 350;
    } else {
        new_speed = speed + (rand() % 20 - 5);
    }
    return new_speed;
}

void run(struct Runner *runner) {
    runner->speed = increase_speed(runner->speed);

    if (runner->speed > runner->max_speed) {
        runner->max_speed = runner->speed;
    }

    runner->distance += runner->speed;


    printf("Runner%d's Speed : %d cm/s\t (%.2lf km/h)\n"
           "Runner%d's Distance : %d cm\t (%.2lf m)\t (%.2lf %%)\n",
           runner->runner_number, runner->speed, (0.036 * runner->speed), runner->runner_number, runner->distance,
           (0.01 * runner->distance),
           ((double) runner->distance / TOTAL_DISTANCE * 100.0));                       // Displaying Runner's stats


    if (runner->distance < TOTAL_DISTANCE && !(runner->distance % OBSTACLE_DISTANCE)) { // Obstacle collision check
        printf("\n\t\t\tRunner %d hit an obstacle!\n\n", runner->runner_number);
        runner->speed = 0;
        runner->tripped++;
    }
}

void finish(struct Runner *runner, int seconds) {
    printf("Runner %d won in %d seconds (%d minutes %d seconds) with the max speed of %d cm/s (%.2lf km/h), tripped %d times!\n",
           runner->runner_number, seconds, (seconds / 60), (seconds % 60), runner->max_speed,
           (0.036 * runner->max_speed),
           runner->tripped);

}

void race() {
    int total_distance = 40000, seconds = 0;

    srand(time(NULL));

    struct Runner runner1 = {1, 0, 0, 0, 0};
    struct Runner *runner1ptr = &runner1;

    struct Runner runner2 = {2, 0, 0, 0, 0};
    struct Runner *runner2ptr = &runner2;


    do {
        seconds++;

        run(runner1ptr);
        run(runner2ptr);

        printf("________________________________________________________________________________\n\n");

    } while (runner1ptr->distance < total_distance && runner2ptr->distance < total_distance);

    // If only one runner managed to cross the finish line he/she will be the winner
    // If both of the runners managed to cross the finish line the one with more distance will be the winner
    if (runner1ptr->distance > runner2ptr->distance) {
        finish(runner1ptr, seconds);
    } else {
        finish(runner2ptr, seconds);
    }
}
