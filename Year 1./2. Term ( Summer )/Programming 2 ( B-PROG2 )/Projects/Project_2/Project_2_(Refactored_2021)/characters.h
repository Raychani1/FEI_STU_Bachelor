#ifndef PROJECT_2__REFACTORED_2021__CHARACTERS_H
#define PROJECT_2__REFACTORED_2021__CHARACTERS_H

// Includes

#include <stdbool.h>
#include "monster_hunt.h"
#include "arena_visualization.h"


// Calculations

#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846


// Power Up attributes

#define POWER_UP_PROXIMITY 3

// Monster attributes

#define MONSTER_STEP 2
#define MONSTER_PROXIMITY 5

// Power Up Functions

bool check_power_up_collision(Hunter *hunter, Monster *monster, Coordinates *power_up);

void generate_power_up(Hunter *hunter, Monster *monster, Coordinates *power_up);

void pick_up_power_up(Hunter *hunter, Monster *monster, Coordinates *power_up);


// Monster Functions

bool check_monster_collision(Hunter *hunter, Monster *monster);

void generate_monster_coordinates(Hunter *hunter, Monster *monster);


// Movement Functions

void change_direction(Hunter *hunter);

void off_arena_movement(Coordinates *coordinates);

void calculate_new_position(Coordinates *old_coordinates, int alpha, int step_size);

void move_hunter(Hunter *hunter);

void generate_new_monster_direction(Monster *monster);

void move_monster(Monster *monster);

void generate_new_coordinates(Coordinates *coordinates);

#endif //PROJECT_2__REFACTORED_2021__CHARACTERS_H
