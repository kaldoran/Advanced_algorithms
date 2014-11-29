//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_rem.c                         |
// DATE : 25/11/14                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "error.h"
#include "stack.h"
#include "solution.h"
#include "readfile.h"
#include "edges_matrix.h"
#include "struct_graph.h"
#include "greedy_approch.h"
#include "branch_and_bound_rem.h"

//static int min_bound = INT_MIN;


//Solution branch_and_bound_rec_rem(int** matrix, int** matrix_l){

//}

Solution branch_and_bound_rem(Graph tspGraph){
	int start = 0;
	
	int** matrix = graph_to_edges_matrix(tspGraph);
	print_edges_matrix(matrix,tspGraph->count_nodes);
	
	int** matrix_red = new_matrix(tspGraph->count_nodes);	
	int bnd = red_line(matrix,matrix_red,tspGraph->count_nodes);
	print_edges_matrix(matrix_red,tspGraph->count_nodes);
	
	printf("bound: %d\n",bnd);

	bnd += red_col(matrix_red,matrix_red,tspGraph->count_nodes);
	print_edges_matrix(matrix_red,tspGraph->count_nodes);	
	
	int first = min_line(matrix, tspGraph->count_nodes, start);
	printf("bound: %d  first: %d\n",bnd,first);
	
	Solution best = greedy_approch(tspGraph);
	
	free_matrix(matrix,tspGraph->count_nodes);
	free_matrix(matrix_red,tspGraph->count_nodes);
	
	return best;
}
































