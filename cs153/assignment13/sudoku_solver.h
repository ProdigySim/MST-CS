#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

/*
	Most of these defines are unnecessary, because of the 
	symmetries of the sudoku board, but they will be nice 
	if I/someone ever wants to modify this code to support
	a strange sudoku variant.
	At the very least, someone could update this to support
	larger sudoku boards. e.g. 4^4 cells, 5^4 cells...
*/

// The basic sudoku board can be expanded, but
// its size must be based on a single square
#define BOX_WIDTH           3
// Constant for all standard sudoku
#define CRITERIA_TYPES      4
#define BOX_SIZE            (BOX_WIDTH*BOX_WIDTH) // 9
#define NUM_BOXES           BOX_SIZE // 9
#define VALID_NUMBERS       BOX_SIZE // 9
#define NUM_COLS            BOX_SIZE // 9
#define NUM_ROWS            NUM_COLS // 9
#define NUM_CELLS           (NUM_ROWS*NUM_COLS) // 81
#define NUM_CRITERIA         (NUM_CELLS*CRITERIA_TYPES) // 324
#define NUM_POSSIBILITIES   (NUM_CELLS*VALID_NUMBERS)) // 728

bool sudoku_solve(unsigned int board[NUM_ROWS][NUM_COLS]);

#endif