#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "monster_hunt.h"
#include "characters.h"
#include "arena_visualization.h"


// Game Functions

double distance(Hunter *hunter, Coordinates *coordinates) {
    return sqrt(pow(hunter->coordinates.x - coordinates->x, 2) + pow(hunter->coordinates.y - coordinates->y, 2));
}

void game() {
    srand(time(NULL));


    Hunter hunter = {{rand() % ARENA_W, rand() % ARENA_H}, 1, 0, 0};
    Monster monster = {{0, 0}, MONSTER_STEP, rand() % 360};

    Hunter *hunter_ptr = &hunter;
    Monster *monster_ptr = &monster;

    generate_monster_coordinates(hunter_ptr, monster_ptr);

    Coordinates power_up;
    Coordinates *power_up_ptr = &power_up;

    generate_power_up(hunter_ptr, monster_ptr, power_up_ptr);

    while (distance(hunter_ptr, &monster_ptr->coordinates) > MONSTER_PROXIMITY) {
        arena_visualization(hunter_ptr, monster_ptr, power_up_ptr);
        move_hunter(hunter_ptr);
        pick_up_power_up(hunter_ptr, monster_ptr, power_up_ptr);
        move_monster(monster_ptr);
    }

    printf("\nThe Hunter caught the Monster!\n");
}