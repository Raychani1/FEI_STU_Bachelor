#ifndef CHESS_H
#define CHESS_H

// 1 Oznacenia na sachovnici

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else
#include <unistd.h>
#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif

#define EMPTY_SQUARE  ' '  // policko bez figurky

// 1.1 Kody figuriek cierneho hraca

#define B_PAWN 'p'   // pesiak
#define B_ROOK 'v'   // veza
#define B_KNIGHT 'j' // jazdec
#define B_BISHOP 's' // strelec
#define B_QUEEN 'd'  // dama
#define B_KING 'k'   // kral

// 1.2 Kody figuriek bieleho hraca

#define W_PAWN 'P'    // pesiak
#define W_ROOK 'V'  // veza
#define W_KNIGHT 'J'  // jazdec
#define W_BISHOP 'S'  // strelec
#define W_QUEEN 'D'   // dama
#define W_KING 'K'    // kral

// 2 Pomocne konstanty

#define L 9 // rozmer sachovnice
#define WHITE_PLAYER_ID 0 // id bieleho hraca
#define BLACK_PLAYER_ID 1 // id cierneho hraca

// 3 Deklaracie premennych
extern char chessboard[L][L]; // sachovnica

// 4 Deklaracie povinnych funkcii (rozhranie sachoveho modulu)
void print_chessboard(); // funkcia vypis aktualnej sachovnice
void init_chessboard(); // funkcia na pociatocne rozostavenie figurok na sachovnici
int move(int srow, int scol, int trow, int tcol, int p_id); // funkcia na realizaciu pohybu figurkou

#endif // CHESS_H