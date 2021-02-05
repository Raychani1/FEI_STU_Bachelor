#include "chess.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>

char chessboard[L][L];
int kontrola_policka(int srow, int scol)
{
    if (chessboard[srow][scol] == ' ')
    {
        return 0;

    }
    else
    {
        return 1;
    }
}
int abc2num(char x)
{
    switch(x)
    {
        case'a':return 1; break;
        case'b':return 2; break;
        case'c':return 3; break;
        case'd':return 4; break;
        case'e':return 5; break;
        case'f':return 6; break;
        case'g':return 7; break;
        case'h':return 8; break;
    }

}
int id_check(int srow, int scol, int p_id)
{
    int id_checker=0;
    if (chessboard[srow][scol] >= 97 && chessboard[srow][scol] <= 122)
    {
        id_checker = 1;
    }
    if (chessboard[srow][scol] >= 65 && chessboard[srow][scol] <= 90)
    {
        id_checker = 0;
    }
    if (id_checker == p_id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int kontrola_nerovnosti(int srow, int scol, int trow, int tcol)
{
    if (chessboard[srow][scol] != chessboard[trow][tcol])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int kontola_ciel(int trow, int tcol, int p_id)
{
    int p_id1=2;
    if (chessboard[trow][tcol] >= 97 && chessboard[trow][tcol] <= 122)
    {
        p_id1 = 1;
    }
    if (chessboard[trow][tcol] >= 65 && chessboard[trow][tcol] <= 90)
    {
        p_id1 = 0;
    }
    if (p_id1 == p_id)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int veza_check(int srow, int scol, int trow, int tcol)
{
    if (tcol == scol)
    {
        if (trow > srow)
        {
            for (int i = srow+1; i <trow; i++)
            {
                if (chessboard[i][scol]!= EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;

                }
                else
                {
                    continue;
                }

            }
        }
        if (trow < srow)
        {
            for (int i = trow+1; i <srow; i++)
            {
                if (chessboard[i][scol] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        if (trow == srow)
        {
            if (tcol > scol)
            {
                for (int i = scol+1; i < tcol; i++)
                {
                    if (chessboard[srow][i] != EMPTY_SQUARE)
                    {
                        printf("Prekazka");
                        return 0;
                    }

                }
            }
            if (tcol < scol)
            {
                for (int i = tcol+1; i < scol; i++)
                {
                    if (chessboard[srow][i] != EMPTY_SQUARE)
                    {
                        printf("Prekazka");
                        return 0;
                    }

                }
            }
        }
    }
    return 1;
}
int veza(int srow, int scol, int trow, int tcol)
{
    if ((scol == tcol) || (srow == trow))
    {
        veza_check(srow, scol, trow, tcol);
    }
    else
    {
        return 0;
    }
}
int kral(int srow, int scol, int trow, int tcol)
{
    if ((abs(srow - trow) == 1) || (abs(scol - tcol) == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int strelec_check(int srow, int scol, int trow, int tcol)
{
    if ((scol < tcol) && (srow < trow))
    {
        int x = abs(scol - tcol);
        for (int i = 1; i < x; i++)
        {
            if (chessboard[srow+i][scol+i] != EMPTY_SQUARE)
            {
                printf("Prekazka");
                return 0;
            }
        }
    }
    if ((scol < tcol) && (srow > trow))
    {
        int x = abs(scol - tcol);
        for (int i = 1; i < x; i++)
        {
            if (chessboard[srow -i][scol + i] != EMPTY_SQUARE)
            {
                printf("Prekazka");
                return 0;
            }
        }
    }
    if ((scol > tcol) && (srow > trow))
    {
        int x = abs(scol - tcol);
        for (int i = 1; i < x; i++)
        {
            if (chessboard[srow - i][scol - i] != EMPTY_SQUARE)
            {
                printf("Prekazka");
                return 0;
            }
        }
    }
    if ((scol > tcol) && (srow < trow))
    {
        int x = abs(scol - tcol);
        for (int i = 1; i <x; i++)
        {
            if (chessboard[srow + i][scol - i] != EMPTY_SQUARE)
            {
                printf("Prekazka");
                return 0;
            }
        }
    }
    return 1;
}
int strelec(int srow, int scol, int trow, int tcol)
{
    if (abs(srow-trow)==abs(tcol-scol))
    {
        strelec_check(srow, scol, trow, tcol);
    }
    else
    {
        return 0;
    }
}
int dama_check(int srow, int scol, int trow, int tcol)
{
    if (tcol == scol)
    {
        if (trow > srow)
        {
            for (int i = srow + 1; i < trow; i++)
            {
                if (chessboard[i][scol] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;

                }
                else
                {
                    continue;
                }

            }
        }
        if (trow < srow)
        {
            for (int i = trow + 1; i < srow; i++)
            {
                if (chessboard[i][scol] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        if (trow == srow)
        {
            if (tcol > scol)
            {
                for (int i = scol + 1; i < tcol; i++)
                {
                    if (chessboard[srow][i] != EMPTY_SQUARE)
                    {
                        printf("Prekazka");
                        return 0;
                    }

                }
            }
            if (tcol < scol)
            {
                for (int i = tcol + 1; i < scol; i++)
                {
                    if (chessboard[srow][i] != EMPTY_SQUARE)
                    {
                        printf("Prekazka");
                        return 0;
                    }

                }
            }
        }
        if ((scol < tcol) && (srow < trow))
        {
            int x = abs(scol - tcol);
            for (int i = 1; i < x; i++)
            {
                if (chessboard[srow + i][scol + i] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
            }
        }
        if ((scol < tcol) && (srow > trow))
        {
            int x = abs(scol - tcol);
            for (int i = 1; i < x; i++)
            {
                if (chessboard[srow - i][scol + i] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
            }
        }

        if ((scol > tcol) && (srow > trow))
        {
            int x = abs(scol - tcol);
            for (int i = 1; i < x; i++)
            {
                if (chessboard[srow - i][scol - i] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
            }
        }
        if ((scol > tcol) && (srow < trow))
        {
            int x = abs(scol - tcol);
            for (int i = 1; i < x; i++)
            {
                if (chessboard[srow + i][scol - i] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
            }
        }
    }
    return 1;
}
int dama(int srow, int scol, int trow, int tcol)
{
    if ((abs(srow - trow) == abs(tcol - scol)) || (scol == tcol) || (srow == trow))
    {
        dama_check(srow, scol, trow, tcol);
    }
    else
    {
        return 0;
    }
}
int jazdec(int srow, int scol, int trow, int tcol)
{
    if (((abs(scol - tcol) == 2) && (abs(srow - trow) == 1)) || ((abs(scol - tcol) == 1) && (abs(srow - trow) == 2)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pesiak(int srow, int scol, int trow, int tcol, int p_id)
{
    if (tcol != scol)
    {
        if (chessboard[trow][tcol] != EMPTY_SQUARE)
        {
            return 1;
        }
    }

    if (chessboard[trow][tcol] != EMPTY_SQUARE)
    {
        printf("Prekazka\n");
        return 0;
    }
    if (p_id==0 && srow<trow)
    {

        return 0;
    }
    if (p_id == 1 && srow > trow)
    {

        return 0;
    }
    if (tcol == scol)
    {
        if (trow > srow)
        {
            for (int i = srow + 1; i < trow; i++)
            {
                if (chessboard[i][scol] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
                else
                {
                    continue;
                }

            }
        }
        if (trow < srow)
        {
            for (int i = trow + 1; i < srow; i++)
            {
                if (chessboard[i][scol] != EMPTY_SQUARE)
                {
                    printf("Prekazka");
                    return 0;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    if ((chessboard[srow][scol] == W_PAWN && p_id == 0 && srow-2==trow&&srow==6) || (chessboard[srow][scol] == B_PAWN && p_id == 1 && srow + 2 == trow&&srow==1))
    {
        return 1;
    }
    if ((tcol == scol && trow == srow - 1 && p_id == 0) || (tcol == scol && trow == srow + 1 && p_id == 1)) {
        return 1;
    }
    else {
        return 0;
    }
    if (chessboard[trow][tcol] == EMPTY_SQUARE) {
        return 1;
    }
    else { return 0; }
}
void print_chessboard() {
    CLEAR_SCREEN();
    printf("\t\t      Cierny \n");
    for (int i = 0; i <L-1; i++)
    {
        printf("\t%c ", chessboard[i][0]);
        for (int j = 1; j <L; j++)
        {
            printf("[%c] ", chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\t%c", chessboard[L - 1][0]);
    for ( int i = 1; i <L; i++)
    {
        printf("  %c ", chessboard[L-1][i]);
    }
    printf("\n\t\t       Biely \n");
}
void init_chessboard()
{
    for (int i = 0; i <L; i++)
    {
        if (i == 0)
        {
            chessboard[i][0] = '8';
            chessboard[i][1] = B_ROOK;
            chessboard[i][2] = B_KNIGHT;
            chessboard[i][3] = B_BISHOP;
            chessboard[i][4] = B_QUEEN;
            chessboard[i][5] = B_KING;
            chessboard[i][6] = B_BISHOP;
            chessboard[i][7] = B_KNIGHT;
            chessboard[i][8] = B_ROOK;
        }
        if (i == 1)
        {
            chessboard[i][0] = '7';
            for (int j = 1; j <= 8; j++)
            {
                chessboard[i][j] = B_PAWN;
            }

        }
        if (i == 2)
        {
            chessboard[i][0] = '6';
            for (int j = 1; j <= 8; j++)
            {
                chessboard[i][j] = EMPTY_SQUARE;
            }

        }
        if (i == 3)
        {
            chessboard[i][0] = '5';
            for (int j = 1; j <= 8; j++)
            {
                chessboard[i][j] = EMPTY_SQUARE;
            }

        }
        if (i == 4)
        {
            chessboard[i][0] = '4';
            for (int j = 1; j <= 8; j++)
            {
                chessboard[i][j] = EMPTY_SQUARE;
            }

        }
        if (i == 5)
        {
            chessboard[i][0] = '3';
            for (int j = 1; j <= 8; j++)
            {
                chessboard[i][j] = EMPTY_SQUARE;
            }

        }
        if (i == 6)
        {

            chessboard[i][0] = '2';
            for (int j = 1; j <= 8; j++)
            {
                chessboard[i][j] = W_PAWN;
            }


        }
        if (i == 7)
        {
            chessboard[i][0] = '1';
            chessboard[i][1] = W_ROOK;
            chessboard[i][2] = W_KNIGHT;
            chessboard[i][3] = W_BISHOP;
            chessboard[i][4] = W_QUEEN;
            chessboard[i][5] = W_KING;
            chessboard[i][6] = W_BISHOP;
            chessboard[i][7] = W_KNIGHT;
            chessboard[i][8] = W_ROOK;
        }
        if (i == L - 1)
        {
            chessboard[L - 1][0] = ' ';
            char x = 96;
            for (int j = 1; j <= 8; j++)
            {
                chessboard[i][j] = x + j;
            }
        }
    }
}
int move(int srow, int scol, int trow, int tcol, int p_id)
{
    while (1)
    {
        if (p_id == WHITE_PLAYER_ID)
        {
            printf("\nBiely na rade: ");
        }
        else
        {
            printf("\nCierny na rade: ");
        }

        char scol1, tcol1;

        scanf(" %c",&scol1);
        scol = abc2num(scol1);
        scanf("%d", &srow);
        srow = L - 1 - srow;
        scanf(" %c", &tcol1);
        tcol = abc2num(tcol1);
        scanf("%d", &trow);
        trow = L-1-trow;

        if ((srow>= L-1 ||srow <0)|| (scol >= L || scol < 0)|| (trow >= L-1 || trow < 0)|| (tcol >= L || tcol < 0))
        {
            printf("Zadali ste suradnicu(e) mimo sachovnice! Skuste este raz!\n");
            printf("1. %c\n", chessboard[srow][scol]);
            printf("2. %c", chessboard[trow][tcol]);
            continue;
        }
        int x;
        x = kontrola_policka(srow, scol);
        if (x == 0)
        {
            printf("\nNa policku sa nenachadza ziadna figurka!Skuste este raz!\n");
            printf("%c", chessboard[srow][scol]);
            printf("%c", chessboard[trow][tcol]);
            continue;
        }
        else
        {
            int x;
            x = id_check(srow, scol,p_id);
            if (x == 0)
            {
                printf("\nTato figurka figurka Vam nepatri!Skuste este raz!\n");
                printf("%c", chessboard[srow][scol]);
                printf("%c", chessboard[trow][tcol]);
                continue;
            }
            else
            {
                int x;
                x = kontrola_nerovnosti(srow, scol, trow, tcol);
                if (x == 0)
                {
                    printf("\nStartovacie a cielove policka su rovnake!Skuste este raz!\n");
                    printf("%c", chessboard[srow][scol]);
                    printf("%c", chessboard[trow][tcol]);
                    continue;
                }
                else
                {

                    if ((chessboard[srow][scol] == B_PAWN) || (chessboard[srow][scol] == W_PAWN))
                    {
                        int y;
                        y = pesiak(srow, scol, trow, tcol,p_id);
                        if (y == 0)
                        {
                            printf("\nZadali ste neplatny tah pre tuto figurku! Skuste este raz!\n");
                            printf("%c", chessboard[srow][scol]);
                            printf("%c", chessboard[trow][tcol]);
                            continue;
                        }
                        if (y == 1)
                        {
                            int x;
                            x = kontola_ciel(trow, tcol, p_id);
                            if (x==0)
                            {
                                printf("\nNa cielovom policku mate figurku! Skuste este raz!\n");
                                printf("%c", chessboard[srow][scol]);
                                printf("%c", chessboard[trow][tcol]);
                                continue;
                            }
                            else
                            {
                                chessboard[trow][tcol] = chessboard[srow][scol];
                                chessboard[srow][scol] = EMPTY_SQUARE;
                                break;
                            }
                        }
                    }
                    if ((chessboard[srow][scol] == B_ROOK) || (chessboard[srow][scol] == W_ROOK))
                    {
                        int y;
                        y = veza(srow, scol, trow, tcol);
                        if (y == 0)
                        {
                            printf("\nZadali ste neplatny tah pre tuto figurku! Skuste este raz!\n");
                            printf("%c", chessboard[srow][scol]);
                            printf("%c", chessboard[trow][tcol]);
                            continue;
                        }
                        if (y == 1)
                        {
                            int x;
                            x = kontola_ciel(trow, tcol, p_id);
                            if (x == 0)
                            {
                                printf("\nNa cielovom policku mate figurku! Skuste este raz!\n");
                                printf("%c", chessboard[srow][scol]);
                                printf("%c", chessboard[trow][tcol]);
                                continue;
                            }
                            else
                            {
                                chessboard[trow][tcol] = chessboard[srow][scol];
                                chessboard[srow][scol] = EMPTY_SQUARE;
                                break;
                            }
                        }
                    }
                    if ((chessboard[srow][scol] == B_KNIGHT) || (chessboard[srow][scol] == W_KNIGHT))
                    {
                        int x;
                        x = jazdec(srow, scol, trow, tcol);
                        if (x == 0)
                        {
                            printf("\nZadali ste neplatny tah pre tuto figurku! Skuste este raz!\n");
                            printf("%c", chessboard[srow][scol]);
                            printf("%c", chessboard[trow][tcol]);
                            continue;
                        }
                        else
                        {
                            int x;
                            x = kontola_ciel(trow, tcol, p_id);
                            if (x == 0)
                            {
                                printf("\nNa cielovom policku mate figurku! Skuste este raz!\n");
                                printf("%c", chessboard[srow][scol]);
                                printf("%c", chessboard[trow][tcol]);
                                continue;
                            }
                            else
                            {
                                chessboard[trow][tcol] = chessboard[srow][scol];
                                chessboard[srow][scol] = EMPTY_SQUARE;
                                break;
                            }
                        }
                    }
                    if ((chessboard[srow][scol] == B_BISHOP) || (chessboard[srow][scol] == W_BISHOP))
                    {
                        int y;
                        y = strelec(srow, scol, trow, tcol);
                        if (y == 0)
                        {
                            printf("\nZadali ste neplatny tah pre tuto figurku! Skuste este raz!\n");
                            printf("%c", chessboard[srow][scol]);
                            printf("%c", chessboard[trow][tcol]);
                            continue;
                        }
                        if (y == 1)
                        {
                            int x;
                            x = kontola_ciel(trow, tcol, p_id);
                            if (x == 0)
                            {
                                printf("\nNa cielovom policku mate figurku! Skuste este raz!\n");
                                printf("%c", chessboard[srow][scol]);
                                printf("%c", chessboard[trow][tcol]);
                                continue;
                            }
                            else
                            {
                                chessboard[trow][tcol] = chessboard[srow][scol];
                                chessboard[srow][scol] = EMPTY_SQUARE;
                                break;
                            }
                        }
                    }
                    if ((chessboard[srow][scol] == B_QUEEN) || (chessboard[srow][scol] == W_QUEEN))
                    {
                        int y;
                        y = dama(srow, scol, trow, tcol);
                        if (y == 0)
                        {
                            printf("\nZadali ste neplatny tah pre tuto figurku! Skuste este raz!\n");
                            printf("%c", chessboard[srow][scol]);
                            printf("%c", chessboard[trow][tcol]);
                            continue;
                        }
                        if (y == 1)
                        {
                            int x;
                            x = kontola_ciel(trow, tcol, p_id);
                            if (x == 0)
                            {
                                printf("\nNa cielovom policku mate figurku! Skuste este raz!\n");
                                printf("%c", chessboard[srow][scol]);
                                printf("%c", chessboard[trow][tcol]);
                                continue;
                            }
                            else
                            {
                                chessboard[trow][tcol] = chessboard[srow][scol];
                                chessboard[srow][scol] = EMPTY_SQUARE;
                                break;
                            }
                        }
                    }
                    if ((chessboard[srow][scol] == B_KING) || (chessboard[srow][scol] == W_KING))
                    {
                        int y;
                        y = kral(srow, scol, trow, tcol);
                        if (y == 0)
                        {
                            printf("\nZadali ste neplatny tah pre tuto figurku! Skuste este raz!\n");
                            printf("%c", chessboard[srow][scol]);
                            printf("%c", chessboard[trow][tcol]);
                            continue;
                        }
                        if (y == 1)
                        {
                            int x;
                            x = kontola_ciel(trow, tcol, p_id);
                            if (x == 0)
                            {
                                printf("\nNa cielovom policku mate figurku! Skuste este raz!\n");
                                printf("%c", chessboard[srow][scol]);
                                printf("%c", chessboard[trow][tcol]);
                                continue;
                            }
                            else
                            {
                                chessboard[trow][tcol] = chessboard[srow][scol];
                                chessboard[srow][scol] = EMPTY_SQUARE;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}