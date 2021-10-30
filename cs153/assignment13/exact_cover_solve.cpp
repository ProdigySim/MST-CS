#include <iostream>
#include "exact_cover_solve.h"

using std::cout;
using std::endl;

void debug_print_head(ec_head *column)
{
	cout << "Col: " << column;
	cout << " id: " << column->head_id << " s: " << column->size;
	cout << " l: " << column->left << " r: " << column->right;
	cout << " hu:" << column->headnode.up << " hd " << column->headnode.down;
	cout << endl;
}

void debug_print_node(ec_node *node)
{
	cout << "node: " << node;
	cout << " h: " << node->head;
	cout << " l: " << node->left << " r: " << node->right;
	cout << " u:" << node->up << " d " << node->down;
	cout << endl;
}

ec_head *select_col_S_Heuristic(ec_head *boardhead)
{
	ec_head *column = boardhead;
	ec_head *retcol;
	unsigned int min_size = (unsigned int)(-1);
	
	// Find the smallest of our columns
	while( (column = column->right) != boardhead)
	{
		if (column->size == 0)
		{
			// This solution is impossible
			return NULL;
		}
		if (column->size < min_size)
		{
			// This is the size of our smallest column
			min_size = column->size;
			// And this is that column
			retcol = column;
		}
	}

	return retcol;
}

void cover (ec_head *column)
{
	ec_node *col_node, *row_node;
	debug_print_head(column);
	
	// Remove this column from our board
	column->right->left = column->left;
	column->left->right = column->right;
	
	col_node = &(column->headnode);
	debug_print_node(col_node);
	// Remove all rows in this column from the matrix of possible solutions
	while ((col_node = col_node->down) != &(column->headnode))
	{
		row_node = col_node;
		debug_print_node(col_node);
		// Scroll through each row to unlink nodes from their columns
		while ((row_node = row_node->right) != col_node)
		{
			debug_print_node(row_node);
			row_node->head->size--;
			row_node->up->down = row_node->down;
			row_node->down->up = row_node->up;
		}
	}
}

void uncover (ec_head *column)
{
	ec_node *col_node, *row_node;
	
		
	col_node = &(column->headnode);

	// Reinsert all rows in this column to the matrix of possible solutions
	while ((col_node = col_node->up) != &(column->headnode))
	{
		
		row_node = col_node;
		// Scroll through each row to relink nodes to their columns
		while ((row_node = row_node->left) != col_node)
		{
			row_node->head->size++;
			row_node->up->down = row_node;
			row_node->down->up = row_node;
		}
	}
	
	// Reinsert this column to our board
	column->right->left = column;
	column->left->right = column;
}

void select (ec_node *row_node, Stack<ec_node> &answer_rows)
{
	ec_node *temp = row_node;
	while ((temp = temp->right) != row_node)
		{
			cover(temp->head);
		}
		answer_rows.push(*row_node);
}

void deselect(ec_node *row_node, Stack<ec_node> &answer_rows)
{
	ec_node *temp = row_node;
	while ((temp = temp->left) != row_node)
		{
			uncover(temp->head);
		}
	answer_rows.pop();
}

unsigned int level;
//Stack<ec_node*> answers;

// Error checking is for laggers
bool exact_cover_solve(ec_head &boardhead, Stack<ec_node> &answer_rows){
	level++;
	cout << "Level: " << level << endl;
	ec_head *column;
	ec_node *col_node, *row_node;
	
	debug_print_head(&boardhead);
	
	if (boardhead.right == &boardhead)
	{
		return true;
	}
	
	column = select_col_S_Heuristic(&boardhead);
	// select_col... returns NULL if it finds a 0 sized column.
	if (column == NULL)
		return false;
	debug_print_head(column);
	
	// "Cover" this column
	cover(column);
	
	col_node = &(column->headnode);
	// Try selecting each row in this column
	while ((col_node = col_node->down) != &(column->headnode))
	{
		select(col_node, answer_rows);
		
		if(exact_cover_solve(boardhead, answer_rows))
		{
			return true;
		}
		
		level--;
		cout << "Level: " << level << endl;
		deselect(col_node, answer_rows);		
	}
	
	uncover(column);
	
	return false;
	
}