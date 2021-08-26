#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Sudoku
{
    struct Square *** squares;
    struct Box ** boxes;
} Sudoku;


typedef struct Box
{
    struct Square ** squares;
    int numbers;
    int possible[9];
    int solvable;
    struct Box * next;
} Box;

typedef struct Square
{
    /* var number holds the number which is in the square */
    int number;
    int possible[9];
    /* solvable = 1 if square is unsolved, solvable = 0 if solves */
    int solvable;
    Box * box;
    int row;
    int column;
} Square;

int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Sudoku * setUpPuzzle(int ** puzzle);

Sudoku * createSudoku(Square *** squares, Box ** boxes);

int updateSudoku(Square *** sudoku, int row, int column);
int checkPuzzle(Square *** sudoku, Box ** boxes);

int solveSquare(Square * square);

/* box functions */
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int column);
int boxSingles(Square *** sudoku, Box ** boxes);

#endif // SUDOKU_H