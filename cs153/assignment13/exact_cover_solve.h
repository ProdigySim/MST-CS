#ifndef EXACT_COVER_SOLVE_H
#define EXACT_COVER_SOLVE_H
#include "stack.h"

typedef struct ec_node_struct ec_node;
typedef struct ec_head_struct ec_head;

typedef struct ec_node_struct {
	ec_head *head;
	ec_node *left;
	ec_node *right;
	ec_node *up;
	ec_node *down;
} ec_node;

typedef struct ec_head_struct {
	unsigned int head_id;
	unsigned int size;
	ec_head *left;
	ec_head *right;
	ec_node headnode;
} ec_head;

void debug_print_head(ec_head *column);
void debug_print_node(ec_node *node);
void cover (ec_head *column);
void uncover (ec_head *column);
void select (ec_node *row_node, Stack<ec_node> &answer_rows);
void deselect(ec_node *row_node, Stack<ec_node> &answer_rows);

// Requires a complete and accurate DLX board
bool exact_cover_solve(ec_head &boardhead, Stack<ec_node> &answer_rows);

#endif