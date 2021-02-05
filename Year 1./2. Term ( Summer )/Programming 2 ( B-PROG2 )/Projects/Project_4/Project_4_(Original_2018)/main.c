#include <stdio.h>
#include "chess.h"
int end_check()
{
    int x = 0;
    for (int i = 0; i < L - 1; i++)
    {
        for (int j = 0; j < L - 1; j++)
        {
            if ((chessboard[i][j] == B_KING) || (chessboard[i][j] == W_KING))
            {
                x += 1;
            }
        }

    }
    return x;
}

int main()
{
    int srow = 0, scol = 0, trow = 0, tcol = 0, p_id = 0;
    print_chessboard();
    init_chessboard();
    int play = 0;
    while (1)
    {

        if (play%2==0)
        {
            p_id = WHITE_PLAYER_ID;
            print_chessboard();
            move(srow, scol, trow, tcol, p_id);
            int y = end_check();
            if (y!=2)
            {
                printf("Biely hrac vyhral!");
                return 0;
            }
            else
            {
                play++;
            }

        }
        else
        {
            p_id = BLACK_PLAYER_ID;
            print_chessboard();
            move(srow, scol, trow, tcol, p_id);
            int y = end_check();
            if (y != 2)
            {
                printf("Cierny hrac vyhral!");
                return 0;
            }
            else
            {
                play++;
            }

        }
    }



    return 0;
}