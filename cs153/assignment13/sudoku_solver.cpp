#include <iostream>
#include "exact_cover_solve.h"
#include "stack.h"

using std::cout;
using std::endl;

typedef struct sudoku_possibility_struct {
	unsigned int row;
	unsigned int col;
	unsigned int val;
} sudoku_possibility;

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

sudoku_possibility interpret_row(ec_node *row_node)
{
	sudoku_possibility thisrow;
	ec_node *p_node = row_node;
	do
	{
		switch (p_node->head->head_id / NUM_CELLS)
		{
			case 0:
				thisrow.row = (p_node->head->head_id % NUM_CELLS)/NUM_COLS;
				thisrow.col = (p_node->head->head_id % NUM_CELLS)%NUM_COLS;
			break;
			case 1:
				thisrow.row = (p_node->head->head_id % NUM_CELLS)/NUM_COLS;
				thisrow.val = (p_node->head->head_id % NUM_CELLS)%NUM_COLS +1;
			break;
			case 2:
				thisrow.col = (p_node->head->head_id % NUM_CELLS)/NUM_COLS;
				thisrow.val = (p_node->head->head_id % NUM_CELLS)%NUM_COLS +1;
			case 3:
			default:
			break;
		}
	} while ((p_node = p_node->right) != row_node);	
	return thisrow;
}

ec_head matrix_headers[NUM_CRITERIA+1];

ec_node matrix_nodes[NUM_CELLS][VALID_NUMBERS][CRITERIA_TYPES];

void ec_insert_before_lr(ec_head *new_node, ec_head *old_node)
{
	new_node->right = old_node;
	new_node->left = old_node->left;
	new_node->left->right = old_node->left = new_node;
}

void ec_insert_before_lr(ec_node *new_node, ec_node *old_node)
{
	new_node->right = old_node;
	new_node->left = old_node->left;
	new_node->left->right = old_node->left = new_node;
}

void ec_insert_before_ud(ec_node *new_node, ec_node *old_node)
{
	new_node->down = old_node;
	new_node->up = old_node->up;
	new_node->up->down = old_node->up = new_node;
}


void populate_sudoku_matrix()
{
	unsigned int criteria_pos, criteria_type;
	
	// For a general visualization of this matrix, see:
	// http://www.stolaf.edu/people/hansonr/sudoku/exactcovermatrix.htm
	
	// Set up our first header, which is actually a robot. (very important)
	matrix_headers[NUM_CRITERIA].left = 
		matrix_headers[NUM_CRITERIA].right = 
		&(matrix_headers[NUM_CRITERIA]);
	
	
	// Run through every header (from right to left)
	for (unsigned int i = 0; i < NUM_CRITERIA; i++)
	{
		ec_insert_before_lr(&(matrix_headers[i]), &(matrix_headers[NUM_CRITERIA]));
		matrix_headers[i].head_id = i;
		// loopback.jpg
		matrix_headers[i].headnode.up =
			matrix_headers[i].headnode.down =
			&(matrix_headers[i].headnode);
		
		// We've got essentially four critiera for each cell for each value.
		// So each column will be sized as the number of possible values.
		matrix_headers[i].size = VALID_NUMBERS;
		
		cout << i << ": ";
		debug_print_head(&(matrix_headers[i]));
		
		criteria_pos = i % NUM_CELLS;
		criteria_type = i / NUM_CELLS;
		cout << "Criteria pos: " << criteria_pos << " type: " << criteria_type << endl;
		// generate NUM_VALUES nodes, and hook them up vertically
		for (unsigned int j = 0; j < VALID_NUMBERS; j++)
		{
			// Point to your head!
			matrix_nodes[criteria_pos][j][criteria_type].head = &(matrix_headers[i]);
			
			ec_insert_before_ud
			(
				&(matrix_nodes[criteria_pos][j][criteria_type]), 
				&(matrix_headers[i].headnode)
			);
		}
		
		unsigned int row, col, val;
		
		// Decide which criteria this column describes
		switch(criteria_type) 
		{
			case 0:
				/* Criteria #1: One value per cell
				
				Each of NUM_ROWS * NUM_COLS represents a single cell
				being filled
				
				So each column in this section represents one cell in our grid
			
				How many possibilities are there for each cell?
					VALID_NUMBERS
				
				So for each column in this section, we will have 
				VALID_NUMBERS nodes
				
				Also, criteria_pos corresponds to our cell #,
				criteria_pos % NUM_COLS corresponds to our column,
				and criteria_pos / NUM_ROWS corresponds to our row
				*/
				row = criteria_pos / NUM_COLS;
				col = criteria_pos % NUM_COLS;
				for (unsigned int k = 0; k < NUM_COLS; k++)
				{
					val = k;
					matrix_nodes[criteria_pos][k][0].left =
						matrix_nodes[criteria_pos][k][0].right =
						&(matrix_nodes[col+(row*NUM_COLS)][val][0]);
				}
			break;
			case 1:
				/* Criteria #2: One of each value per row
				
				
				Which nodes for our first criteria do these correspond to?
					
				*/
				row = criteria_pos/VALID_NUMBERS;
				val = criteria_pos%VALID_NUMBERS;
				// Go through every row for this criteria
				for (unsigned int k = 0; k < NUM_COLS; k++)
				{
					col = k;
					cout << "Row: " << row << " col: " << col << " val: " << val;
					ec_insert_before_lr
					(
						&(matrix_nodes[criteria_pos][k][criteria_type]),
						&(matrix_nodes[col+(row*NUM_COLS)][val][0])
					);
				}
				
			
			break;
			case 2:
				/* Criteria #3: One of each value per column
			
				I got bored of writing
				*/
				col = criteria_pos/VALID_NUMBERS;
				val = criteria_pos%VALID_NUMBERS;
				// Go through every row for this column
				for (unsigned int k = 0; k < NUM_ROWS; k++)
				{
					row = k;
					ec_insert_before_lr
					(
						&(matrix_nodes[criteria_pos][k][criteria_type]),
						&(matrix_nodes[col+(row*NUM_COLS)][val][0])
					);
				}
			break;
			case 3:
				/* Criteria #3: One of each value per box */
				unsigned int block_num, block_offset_row, block_offset_col, block_pos;
				block_num = criteria_pos/VALID_NUMBERS;
				val = criteria_pos%VALID_NUMBERS;
				block_offset_row = (block_num/BOX_WIDTH)*BOX_WIDTH;
				block_offset_col = (block_num%BOX_WIDTH)*BOX_WIDTH;
				for (unsigned int k = 0; k < BOX_SIZE; k++)
				{
					block_pos = k;
					row = (block_pos/3)+block_offset_row;
					col = (block_pos%3)+block_offset_col;
					ec_insert_before_lr
					(
						&(matrix_nodes[criteria_pos][k][criteria_type]),
						&(matrix_nodes[col+(row*NUM_COLS)][val][0])
					);
				}
			break;
			default:
				// This should never happen);
				cout << "Dying!\n";
			break;
		}
		
	}
	
}



// Takes a board where each byte is 0-9 signifying a number or a blank.
bool sudoku_solve(unsigned int board[NUM_ROWS][NUM_COLS])
{
	Stack<ec_node> answer_rows;
	ec_node * row_node;
	sudoku_possibility temp_cell;
	populate_sudoku_matrix();
	
	for (unsigned int i = 0; i < NUM_ROWS; i++)
	{
		for (unsigned int j = 0; j < NUM_COLS; j++)
		{
			if (board[i][j] && board[i][j] <= VALID_NUMBERS)
			{
				select
				(
					// col+(row*NUM_COLS) == cell index.
					// criteria type = 0, so cell index = node index
					// board[i][j]-1 == value, which is 
					&(matrix_nodes[j+(i*NUM_COLS)][(board[i][j]-1)][0]), 
					answer_rows
				);
			}
		}
	}
	
	if(!exact_cover_solve(matrix_headers[NUM_CRITERIA], answer_rows))
	{
		return false;
	}
	
	while (answer_rows.size())
	{
		row_node = answer_rows.top().left->right;
		temp_cell = interpret_row(row_node);
		board[temp_cell.row][temp_cell.col] = temp_cell.val;
		answer_rows.pop();
	}
	
	return true;
}


/*
unsigned int sudoku_board[NUM_ROWS][NUM_COLS];
int main()
{
	Stack<ec_node> answer_rows;
	ec_node * row_node;
	sudoku_possibility row_cell;
	
	populate_sudoku_matrix();
	cout << exact_cover_solve(matrix_headers[NUM_CRITERIA], answer_rows) << endl;
	
	cout << "Rows: " << answer_rows.size() << endl;
	while (answer_rows.size())
	{
		row_node = answer_rows.top().left->right;
		debug_print_node(row_node);
		debug_print_node(&(answer_rows.top()));
		row_cell = interpret_row(row_node);
		sudoku_board[row_cell.row][row_cell.col] = row_cell.val;
		answer_rows.pop();
	}
	for (unsigned int i = 0; i < NUM_ROWS; i++)
	{
		if (i % 3 == 0 && i)
		{
			cout << "-----------" << endl;
		}
		for (unsigned int j = 0; j < NUM_COLS; j++)
		{
			if (j % 3 == 0 && j)
			{
				cout << "|";
			}
			cout << sudoku_board[i][j];
		}
		cout << endl;
	}
	return 0;
} */


