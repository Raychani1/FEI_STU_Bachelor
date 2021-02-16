#ifndef PROJECT_2__REFACTORED_2021__ARENA_VISUALIZATION_H
#define PROJECT_2__REFACTORED_2021__ARENA_VISUALIZATION_H

// Clear Screen Functionality
#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else

#include <unistd.h>

#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif

// Figures
#define MONSTER 'M'
#define HUNTER 'H'
#define POWER_UP '+'

// Arena attributes
#define ARENA_W 30 // 100
#define ARENA_H 30 // 45

#include "monster_hunt.h"

void print_stats(Hunter *hunter, Monster *monster, Coordinates *power_up);

void print_compass(Hunter *hunter);

void print_top_bottom_border();

void print_empty_line();

void print_line_one_object(int x, char figure);

void print_line_two_objects(int x1, char figure1, int x2, char figure2);

void print_line_full(int x1, char figure1, int x2, char figure2, int x3, char figure3);

void print_arena(Hunter *hunter, Monster *monster, Coordinates *power_up);

void arena_visualization(Hunter *hunter, Monster *monster, Coordinates *power_up);

#endif //PROJECT_2__REFACTORED_2021__ARENA_VISUALIZATION_H
