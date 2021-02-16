#ifndef PROJECT_2__REFACTORED_2021__MONSTER_HUNT_H
#define PROJECT_2__REFACTORED_2021__MONSTER_HUNT_H

// Structures

typedef struct {
    double x;
    double y;
} Coordinates;

typedef struct {
    Coordinates coordinates;
    int step;
    int alpha;
    int power_ups;
} Hunter;

typedef struct {
    Coordinates coordinates;
    int step;
    int alpha;
} Monster;


// Functions

// Game Functions

double distance(Hunter *hunter, Coordinates *coordinates);

void game();


#endif //PROJECT_2__REFACTORED_2021__MONSTER_HUNT_H
