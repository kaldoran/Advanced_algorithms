//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_rem.h                         |
// DATE : 25/11/14                                          |
//----------------------------------------------------------

#include "graph.h"



int** graph_to_edges_matrix(Graph tspGraph);
void print_edges_matrix(int** matrix, int length);


//Solution branch_and_bound_rec_rem(Solution part, Solution best, Graph tspGraph, Stack_node* stack);
Solution branch_and_bound_rem(Graph tspGraph);
