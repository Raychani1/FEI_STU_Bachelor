#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "characters.h"


void generate_new_coordinates(Coordinates *coordinates) {
    coordinates->x = rand() % ARENA_W;
    coordinates->y = rand() % ARENA_H;
}

// Power Up Functions

bool check_power_up_collision(Hunter *hunter, Monster *monster, Coordinates *power_up) {
    if (((int) round(power_up->x) == (int) round(hunter->coordinates.x) &&
         (int) round(power_up->y) == (int) round(hunter->coordinates.y)) ||
        ((int) round(power_up->x) == (int) round(monster->coordinates.x) &&
         (int) round(power_up->y) == (int) round(monster->coordinates.y))) {
        return true;
    }
    return false;
}

void generate_power_up(Hunter *hunter, Monster *monster, Coordinates *power_up) {
    do {
        generate_new_coordinates(power_up);
    } while (check_power_up_collision(hunter, monster, power_up));
}

void pick_up_power_up(Hunter *hunter, Monster *monster, Coordinates *power_up) {
    if (distance(hunter, power_up) <= POWER_UP_PROXIMITY) {
        printf("\nThe Hunter picked up a Power Up! Hunter speed increased!\n\n");
        hunter->power_ups++;
        hunter->step = (int) round(hunter->step * 1.5);
        generate_power_up(hunter, monster, power_up);
    }
}


// Monster Functions

bool check_monster_collision(Hunter *hunter, Monster *monster) {
    if (((int) round(monster->coordinates.x) == (int) round(hunter->coordinates.x) &&
         (int) round(monster->coordinates.y) == (int) round(hunter->coordinates.y)) ||
        ((int) round(distance(hunter, &monster->coordinates) <= MONSTER_PROXIMITY))) {
        return true;
    }
    return false;
}

void generate_monster_coordinates(Hunter *hunter, Monster *monster) {
    do {
        generate_new_coordinates(&monster->coordinates);
    } while (check_monster_collision(hunter, monster));
}

void generate_new_monster_direction(Monster *monster) {
    monster->alpha = rand() % 360;
}


// Movement Functions

void change_direction(Hunter *hunter) {
    int direction;

    scanf("%d", &direction);

    switch (direction) {
        case 1:
            hunter->alpha = 135;   // Lower Diagonal to the Left
            break;
        case 2:
            hunter->alpha = 90;     // Down
            break;
        case 3:
            hunter->alpha = 45;     // Lower Diagonal to the Right
            break;
        case 4:
            hunter->alpha = 180;    // Left
            break;
        case 5:                     // Repeat the last direction
            break;
        case 6:
            hunter->alpha = 0;      // Right
            break;
        case 7:
            hunter->alpha = 225;    // Upper Diagonal to the Left
            break;
        case 8:
            hunter->alpha = 270;    // Up
            break;
        case 9:
            hunter->alpha = 315;    // Upper Diagonal to the Right
            break;
        default:
            break;
    }
}

void off_arena_movement(Coordinates *coordinates) {
    if (coordinates->x >= ARENA_W && coordinates->y >= ARENA_H) {
        coordinates->x -= ARENA_W;
        coordinates->y -= ARENA_H;

    } else if (coordinates->x >= ARENA_W && coordinates->y < 0) {
        coordinates->x -= ARENA_W;
        coordinates->y += ARENA_H;

    } else if (coordinates->x < 0 && coordinates->y >= ARENA_H) {
        coordinates->x += ARENA_W;
        coordinates->y -= ARENA_H;

    } else if (coordinates->x < 0 && coordinates->y < 0) {
        coordinates->x += ARENA_W;
        coordinates->y += ARENA_H;

    } else if (coordinates->x < 0) {
        coordinates->x += ARENA_W;

    } else if (coordinates->x >= ARENA_W) {
        coordinates->x -= ARENA_W;

    } else if (coordinates->y < 0) {
        coordinates->y += ARENA_H;

    } else if (coordinates->y >= ARENA_H) {
        coordinates->y -= ARENA_H;

    }
}

void calculate_new_position(Coordinates *old_coordinates, int alpha, int step_size) {
    old_coordinates->x += (step_size * cos((alpha / 180.0) * M_PI));
    old_coordinates->y += (step_size * sin((alpha / 180.0) * M_PI));

    // Recalculations if the character move off the Arena
    off_arena_movement(old_coordinates);
}

void move_hunter(Hunter *hunter) {
    change_direction(hunter);
    calculate_new_position(&hunter->coordinates, hunter->alpha, hunter->step);
}

void move_monster(Monster *monster) {
    generate_new_monster_direction(monster);
    calculate_new_position(&monster->coordinates, monster->alpha, monster->step);
}
