#ifndef PROJECT_1__REFACTORED_2021__STEEPLECHASE_H
#define PROJECT_1__REFACTORED_2021__STEEPLECHASE_H

#define TOTAL_DISTANCE 40000
#define OBSTACLE_DISTANCE 5000

struct Runner;

int increase_speed(int speed);

void run(struct Runner *runner);

void finish(struct Runner *runner, int seconds);

void race();

#endif //PROJECT_1__REFACTORED_2021__STEEPLECHASE_H
