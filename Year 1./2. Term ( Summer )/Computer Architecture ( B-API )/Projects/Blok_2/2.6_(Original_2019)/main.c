#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else

#include <unistd.h>

#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif

int main() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point = {100, 25};
    srand(time(NULL));

    while (true) {
        SetConsoleCursorPosition(hConsole, point);
        clock_t Start, Koniec;
        float Trvanie;
        int x;
        unsigned char ch = 0;

        do {
            if (_kbhit()) {

                ch = _getch();

                switch (ch) {
                    case 27:
                        return 0;
                        break;
                    case 59:
                        CLEAR_SCREEN();
                        printf(" F1 - Navod F2 - Start Esc - Koniec");
                        break;
                    case 60:
                        CLEAR_SCREEN();
                        SetConsoleCursorPosition(hConsole, point);
                        x = rand() % 25 + 65;
                        printf("%c\n\n", x);
                        Start = clock();
                        while (ch != x) {
                            if (_kbhit()) {
                                ch = _getch();
                                if (ch == 27)
                                    return 0;
                                printf("%c ", ch);
                            }
                        }
                        Koniec = clock();
                        Trvanie = (float) (Koniec - Start) / CLOCKS_PER_SEC;
                        printf("\n\n%f sekund\n\n", Trvanie);
                        break;
                }

            }
        } while (ch != 27);
    }

}