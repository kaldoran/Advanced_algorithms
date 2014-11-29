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

int** branch_and_bound_rem_rec(int index, int** part, int part_bound, int part_length,int** best, int best_bound, int best_length){
	if(part_length == best_length){
		if(part_bound < best_bound){
			return part;
		}
	}
	else{
		int next = index_min_line(part, best_length, index);
		int j, left_bound = part_bound, right_bound = part_bound;
		
		
		int** left_part = copy_matrix(part, best_length);
			
		for(j = 0; j < best_length; ++j) {
			left_part[index][j] = -1;
		}
		for(j = 0; j < best_length; ++j) {
			left_part[j][next] = -1;
		}
		left_part[next][index] = -1;
		left_part[index][next] = -2;
		
		left_bound += red_all(left_part, left_part, best_length);
		
		if(left_bound < best_bound){
			best = branch_and_bound_rem_rec(next, left_part, left_bound, part_length+1, best, best_bound, best_length);
		}
		
		
		int** right_part = copy_matrix(part, best_length);
		right_part[index][next] = -1;
		
		right_bound += red_all(right_part, right_part, best_length);
		
		if(right_bound < best_bound){
			best = branch_and_bound_rem_rec(next, left_part, left_bound, part_length+1, best, best_bound, best_length);
		}
	}
	return best;
}

Solution branch_and_bound_rem(Graph tspGraph) {
	int start = 0;
	
	int** matrix = graph_to_edges_matrix(tspGraph);
	
	int** matrix_part = new_matrix(tspGraph->count_nodes);
	
	Solution best = greedy_approch(tspGraph);
	
	int** matrix_best = NULL;
	
	int best_bound =  bound_solution(best, matrix, matrix_best, tspGraph->count_nodes);
	
	matrix_best = branch_and_bound_rem_rec(start, matrix_part, INT_MAX, 0, matrix_best, best_bound, tspGraph->count_nodes);
	
	best = edges_matrix_to_solution(matrix_best, tspGraph->count_nodes);
	
	free_matrix(matrix,tspGraph->count_nodes);
	free_matrix(matrix_part,tspGraph->count_nodes);
	free_matrix(matrix_best,tspGraph->count_nodes);
	
	return best;
}
































