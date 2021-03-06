#include "sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes)
{
    int i, j, k;

    int sum[9];
    int place[9];

    /* loop through all rows */

    for (i = 0; i < 9; i++)
    {  
        /* init sum and place to zeroes */
        for (j = 0; j < 9; j++)
        {
            sum[j] = 0;
            place[j] = 0;
        }
        /* loop through each square in the row */
        for (j = 0; j < 9; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                continue;
            }

            /* loop through all possible array*/
            for (k = 0; k < 9; k++)
            {
                /* check if k is possible */
                if (sudoku[i][j]->possible[k] == 0)
                {
                    sum[k]++;
                    place[k] = j;
                }
            }

        }

        for (k = 0; k < 9; k++)
        {
            if(sum[k] == 1)
            {
                sudoku[i][place[k]]->number = k + 1;
                sudoku[i][place[k]]->solvable = 0;
                UNSOLVED--;

                updateSudoku(sudoku, i, place[k]);
                updateBoxes(sudoku, i, place[k]);

                return 1;
            }
        }

    }

    return 0;
}