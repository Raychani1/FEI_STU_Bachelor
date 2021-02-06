#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define P_MONSTER 'M'
#define P_HUNTER 'H'
#define HUNTER_STEP 5
#define MONSTER_STEP 2
#define MONSTER_PROXIMITY 4
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#define ARENA_W 60
#define ARENA_H 30
#define M_PI 3.14159265358979323846
#define SQR(X)	(X*X)

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else
#include <unistd.h>
#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif

void print_arena(float x_H, float y_H, float x_M, float y_M);
int alpha_H = 0;
int alpha_M = rand() % 360;

float deg2rad(int x)
{
    float r = ((x / 180.0)*M_PI);
    return r;

}
float get_new_x(float old_x, int alpha, int dist)
{
    float new_x = 0.0,alpha1;
    alpha1 = deg2rad(alpha);
    new_x = old_x+(dist * cos(alpha1));
    return new_x;
}
float get_new_y(float old_y, int alpha, int dist)
{
    float new_y = 0.0,alpha1;
    alpha1 = deg2rad(alpha);
    new_y = old_y + (dist * sin(alpha1));
    return new_y;
}
float distance(float x1, float y1, float x2, float y2)
{
    float x, y,r;
    x = x2 - x1;
    y = y2 - y1;
    r = sqrt(SQR(x) + SQR(y));
    return r;
}

int compass(int alpha)
{
    if (alpha == 0 || alpha == 360)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n     \n  O --\n     \n");
    }
    if (alpha>0 && alpha < 90)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n   / \n  O  \n     \n");
    }
    if (alpha == 90)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n  |  \n  O  \n     \n");
    }

    if (alpha > 90 && alpha < 180)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n \\   \n  O  \n     \n");
    }
    if (alpha==180)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n     \n-- O  \n     \n");
    }
    if (alpha > 180 && alpha < 270)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n     \n  O  \n /    \n");
    }
    if (alpha == 270)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n     \n  O  \n  |  \n");
    }
    if (alpha > 270 && alpha < 360)
    {
        printf("\nCurrent hunters angel: %d", alpha);
        printf("\n\n     \n  O  \n   \\ ");
    }
    return 0;
}
int main()
{
    float x_H, y_H, x_M, y_M,d;
    int play = 0;

    srand(time(NULL));
    x_H = rand() % ARENA_W;
    y_H = rand() % ARENA_H;

    x_M = rand() % ARENA_W;
    y_M = rand() % ARENA_H;

    print_arena(x_H, y_H, x_M, y_M);

    d = distance(x_H, y_H, x_M, y_M);

    while (d> MONSTER_PROXIMITY)
    {

        if (play % 2 == 0)
        {
            printf("\n\nVzdialenost medzi Hunter a Monster: %.2f\n", d);
            int s;
            printf("\nHunter zadajte smer\n(Pouzivajte numericku klavesicu - cislo 5 zopakuje naposledy zadany smer) :");
            //printf("\n(1) - dolava\n(2) - dopredu\n(3) - doprava\n");
            scanf("%d", &s);
            switch (s)
            {
                /*version 1.0
                case 1: alpha_H = alpha_H+30; if (alpha_H > 360){alpha_H = alpha_H - 360;} break;
                case 2: alpha_H = alpha_H; break;
                case 3: alpha_H = alpha_H-30; if (alpha_H < 0){alpha_H = alpha_H + 360;} break;
                */

                case 1: alpha_H = 225; break;
                case 2: alpha_H = 270; break;
                case 3: alpha_H = 315; break;
                case 4: alpha_H = 180; break;
                case 6: alpha_H = 0; break;
                case 7: alpha_H = 135; break;
                case 8: alpha_H = 90; break;
                case 9: alpha_H = 45; break;

            }
            x_H = get_new_x(x_H, alpha_H, HUNTER_STEP);
            y_H = get_new_y(y_H, alpha_H, HUNTER_STEP);

            if (y_H <0)
            {
                y_H = ARENA_H+ y_H;
            }
            if (y_H > ARENA_H)
            {
                y_H = 0+ (y_H - ARENA_H );
            }
            if (x_H > ARENA_W)
            {
                x_H = 0 + ( x_H - ARENA_W);
            }
            if (x_H < 0)
            {
                x_H = ARENA_W + x_H;
            }

            print_arena(x_H, y_H, x_M, y_M);
            compass(alpha_H);
            play++;
        }
        else
        {
            printf("\nVzdialenost medzi Hunter a Monster: %.2f \n", d);
            printf("\nMonsters turn");
            alpha_M = rand() % 360;
            x_M=get_new_x(x_M, alpha_M, MONSTER_STEP);
            y_M=get_new_y(y_M, alpha_M, MONSTER_STEP);


            if (y_M < 0)
            {
                y_M = ARENA_H + y_M;
            }
            if (y_M > ARENA_H)
            {
                y_M = 0 + (y_M - ARENA_H);
            }
            if (x_M > ARENA_W)
            {
                x_M = 0 + (x_M - ARENA_W);
            }
            if (x_M < 0)
            {
                x_M = ARENA_W + x_M;
            }

            print_arena(x_H, y_H, x_M, y_M);
            compass(alpha_H);
            play++;
        }
        d = distance(x_H, y_H, x_M, y_M);

    }
    printf("\nCongratulations! Hunter caught the Monster \n");
    return 0;
}

void print_arena(float x_H, float y_H, float x_M, float y_M)
{

    CLEAR_SCREEN();
    printf("ARENA SIZE: %dx%d\n", ARENA_W, ARENA_H);
    printf("(%c) Hunter: (%.2f,%.2f,%d)\n", P_HUNTER, x_H, y_H, alpha_H);
    printf("(%c) Monster: (%.2f,%.2f,%d)\n", P_MONSTER, x_M, y_M, alpha_M);

    y_H = ARENA_H - 1 - y_H;
    y_M = ARENA_H - 1 - y_M;

    int i, j, k;
    char first, second;
    int x_H1 = x_H, y_H1 = y_H, x_M1 = x_M, y_M1 = y_M, first_x, second_x;
    printf(" ");
    for (k = 0; k < ARENA_W + 2; k++)
    {
        printf("_ ");
    }
    printf("\n");

    for (i = -1; i <ARENA_H; i++)
    {
        if (i == y_H1 && i == y_M1)
        {
            printf("| ");
            if (x_H1 < x_M1)
            {
                first = P_HUNTER;
                second = P_MONSTER;
                first_x = x_H1;
                second_x = x_M1;
            }
            else
            {
                first = P_MONSTER;
                second = P_HUNTER;
                first_x = x_M1;
                second_x = x_H1;
            }

            for (j = 0; j < first_x; j++)
            {
                printf("  ");
            }
            printf("%c ", first);

            for (j = first_x + 1; j <second_x; j++)
            {
                printf("  ");
            }
            printf("%c ", second);
            for (j = second_x+1 ; j <ARENA_W+1; j++)
            {
                printf("  ");

            }
            printf("|\n");
        }


        else
        {
            if (i == y_H1)

            {
                printf("| ");
                for (j = 0; j < x_H1; j++)
                {
                    printf("  ");
                }

                printf("%c ", P_HUNTER);
                for (j = x_H1 + 1; j < ARENA_W+1; j++)
                {
                    printf("  ");
                }
                printf("|\n");
            }

            else if (i == y_M1)
            {
                printf("| ");
                for (j = 0; j < x_M1; j++)
                {
                    printf("  ");
                }
                printf("%c ", P_MONSTER);
                for (j = x_M1 + 1; j < ARENA_W + 1; j++)
                {
                    printf("  ");
                }
                printf("|\n");
            }
            else {
                printf("| ");
                for (k = 0; k < ARENA_W + 1; k++)
                {
                    printf("  ");
                }
                printf("|\n");
            }
        }
    }
    printf("|");
    for (k = 0; k < ARENA_W + 1; k++)
    {
        printf("_ ");
    }
    printf("_|\n");
    //getchar();
    //SLEEP(2000);
}