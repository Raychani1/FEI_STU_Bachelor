#include <stdio.h>
#include <windows.h>                          // potrebne pre pracu s WinAPI

const unsigned char RohVpravoDole = 0xd9;     // ostatne si zistite sami!


int main(int argc, char *argv[]) {
    HANDLE hConsole;                           // ziskanie handle konzoly
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int lc = 202;
    int leftcross = 204;
    int rc = 187;
    int line = 205;
    // Suradnice: X:stlpec, Y:riadok
    int stlpec = 39;
    int riadok = 12;
    COORD point = {stlpec, riadok};                      //             point.X = 39;
    SetConsoleCursorPosition(hConsole, point);

    putchar(lc);
    stlpec++;

    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            printf("Záznam 001");
        }
        SetConsoleCursorPosition(hConsole, point);
        printf("%c", line);
        stlpec++;
        point.X = stlpec;
        point.Y = riadok;
    }

    // nastavi sa na [39,12]


    riadok++;
    point.X = 39;
    point.Y = riadok;

    SetConsoleCursorPosition(hConsole, point);
    putchar(leftcross);

    for (int i = 0; i < 10; i++) {
        stlpec++;
        SetConsoleCursorPosition(hConsole, point);
        putchar(line);

        point.X = stlpec;
        point.Y = riadok;
    }


    return (0);
}