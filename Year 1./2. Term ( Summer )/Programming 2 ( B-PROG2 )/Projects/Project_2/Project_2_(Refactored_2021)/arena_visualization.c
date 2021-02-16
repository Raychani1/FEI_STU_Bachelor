#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "monster_hunt.h"
#include "arena_visualization.h"

void print_stats(Hunter *hunter, Monster *monster, Coordinates *power_up) {
    printf("ARENA SIZE: %dx%d\n\n", ARENA_W, ARENA_H);
    printf("Hunter (%c) : ( x : %.2lf, y : %.2lf, alpha : %d, step_size : %d, number of power ups : %d )\n", HUNTER,
           hunter->coordinates.x, hunter->coordinates.y, hunter->alpha, hunter->step, hunter->power_ups);
    printf("Monster (%c) : ( x : %.2lf, y : %.2lf, alpha : %d, step_size : %d)\n", MONSTER, monster->coordinates.x,
           monster->coordinates.y,
           monster->alpha, monster->step);
    printf("Power Up (%c) : ( x : %.2lf, y : %.2lf )\n", POWER_UP, power_up->x, power_up->y);
    printf("\nHunter - Monster Distance: %.2lf\n", distance(hunter, &monster->coordinates));
    printf("Hunter - Power Up Distance: %.2lf\n\n", distance(hunter, power_up));
}

void print_compass(Hunter *hunter) {
    printf("\nHunter's current angle %d\n", hunter->alpha);
    switch (hunter->alpha) {
        case 0:
            printf("     \n  O--\n     \n");
            break;
        case 45:
            printf("     \n  O  \n    \\\n");
            break;
        case 90:
            printf("     \n  O  \n  |  \n");
            break;
        case 135:
            printf("     \n  O  \n/     \n");
            break;
        case 180:
            printf("     \n--O  \n     \n");
            break;
        case 225:
            printf("\\     \n  O  \n      \n");
            break;
        case 270:
            printf("  |  \n  O  \n     \n");
            break;
        case 315:
            printf("    /\n  O  \n     \n");
            break;
    }
}

void print_top_bottom_border() {
    printf("o");
    for (int i = 0; i < ARENA_W; i++) {
        printf(" -");
    }
    printf(" o\n");
}

void print_empty_line() {
    printf("|");
    for (int j = 0; j < ARENA_W; j++) {
        printf("  ");
    }
    printf(" |\n");
}

void print_line_one_object(int x, char figure) {
    printf("|");
    for (int j = 0; j < ARENA_W; j++) {
        if (j == x) {
            printf(" %c", figure);
        } else {
            printf("  ");
        }
    }
    printf(" |\n");
}

void print_line_two_objects(int x1, char figure1, int x2, char figure2) {
    printf("|");
    for (int j = 0; j < ARENA_W; j++) {
        if (j == x1) {
            printf(" %c", figure1);
        } else if (j == x2) {
            printf(" %c", figure2);
        } else {
            printf("  ");
        }
    }
    printf(" |\n");
}

void print_line_full(int x1, char figure1, int x2, char figure2, int x3, char figure3) {
    printf("|");
    for (int j = 0; j < ARENA_W; j++) {
        if (j == x1) {
            printf(" %c", figure1);
        } else if (j == x2) {
            printf(" %c", figure2);
        } else if (j == x3) {
            printf(" %c", figure3);
        } else {
            printf("  ");
        }
    }
    printf(" |\n");
}

void print_arena(Hunter *hunter, Monster *monster, Coordinates *power_up) {
    print_top_bottom_border();
    for (int i = 0; i < ARENA_H; i++) {
        if (i == (int) round(hunter->coordinates.y) &&
            i == (int) round(monster->coordinates.y) &&
            i == (int) round(power_up->y)) {
            print_line_full((int) round(hunter->coordinates.x), HUNTER,
                            (int) round(monster->coordinates.x), MONSTER,
                            (int) round(power_up->x), POWER_UP);

        } else if (i == (int) round(hunter->coordinates.y) &&
                   i == (int) round(power_up->y)) {
            print_line_two_objects((int) round(hunter->coordinates.x), HUNTER,
                                   (int) round(power_up->x), POWER_UP);

        } else if (i == (int) round(monster->coordinates.y) &&
                   i == (int) round(power_up->y)) {
            print_line_two_objects((int) round(monster->coordinates.x), MONSTER,
                                   (int) round(power_up->x), POWER_UP);

        } else if (i == (int) round(hunter->coordinates.y) &&
                   i == (int) round(monster->coordinates.y)) {
            print_line_two_objects((int) round(hunter->coordinates.x), HUNTER,
                                   (int) round(monster->coordinates.x), MONSTER);

        } else if (i == (int) round(hunter->coordinates.y)) {
            print_line_one_object((int) round(hunter->coordinates.x), HUNTER);

        } else if (i == (int) round(monster->coordinates.y)) {
            print_line_one_object((int) round(monster->coordinates.x), MONSTER);

        } else if (i == (int) round(power_up->y)) {
            print_line_one_object((int) round(power_up->x), POWER_UP);

        } else {
            print_empty_line();
        }

    }
    print_top_bottom_border();
}

void arena_visualization(Hunter *hunter, Monster *monster, Coordinates *power_up) {
    CLEAR_SCREEN();
    print_stats(hunter, monster, power_up);
    print_arena(hunter, monster, power_up);
    print_compass(hunter);
}