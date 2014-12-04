//--------------------------------------------------------------
// AUTEUR : BASCOL Kevin                                        |
// FICHIER : branch_and_bound_rem.c                             |
// DATE : 25/11/14                                              |
//                                                              |
// - Implementation of the prototypes in branch_and_bound_rem.h |
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "error.h"
#include "solution.h"
#include "readfile.h"
#include "struct_graph.h"
#include "greedy_approach.h"
#include "branch_and_bound_rem.h"

Edges_matrix branch_and_bound_rem_rec(Edges_matrix part, int part_bound, int part_length,Edges_matrix best, int best_bound, int best_length) {
	if(part_length == best_length) {
		if(part_bound < best_bound) {
			Edges_matrix new_part = copy_matrix(part, part_length);
			
			return new_part;
		}
		
	}
	else{
		int* indexes = first_zero(part,best_length);
		int index = indexes[0];
		int next = indexes[1];

		int j, left_bound = part_bound, right_bound = part_bound;
		
		
		Edges_matrix left_part = copy_matrix(part, best_length);
			
		for(j = 0; j < best_length; ++j) {
			left_part[index][j] = -1;
			left_part[j][next] = -1;
		}
		left_part[next][index] = -1;
		left_part[index][next] = -2;
		
		left_bound += red_all(left_part, left_part, best_length);
		if(left_bound < best_bound) {
			left_part = branch_and_bound_rem_rec(left_part, left_bound, part_length+1, best, best_bound, best_length);
		}
				
		
		Edges_matrix right_part = copy_matrix(part, best_length);
		right_part[index][next] = -1;
		
		right_bound += red_all(right_part, right_part, best_length);
		if(right_bound < best_bound) {
			right_part = branch_and_bound_rem_rec(right_part, right_bound, part_length+1, best, best_bound, best_length);
		}
		if(left_bound < best_bound) {
			best = copy_matrix(left_part,best_length);
		}
		else{
			best = copy_matrix(right_part,best_length);
		}
	}
	return best;
}

Solution branch_and_bound_rem(Graph tspGraph) {
    int start = 0;
    
    Edges_matrix matrix = graph_to_edges_matrix(tspGraph);
    
    Solution best = greedy_approach(tspGraph);
    
    Edges_matrix matrix_best = copy_matrix(matrix, tspGraph->count_nodes);
    
    int best_bound =  bound_solution(best, matrix_best, tspGraph->count_nodes);
    
    matrix_best = branch_and_bound_rem_rec(matrix, 0, 0, matrix_best, best_bound, tspGraph->count_nodes);
    
    best = edges_matrix_to_solution(matrix_best, tspGraph, start);

    free_matrix(matrix,tspGraph->count_nodes);
    free_matrix(matrix_best,tspGraph->count_nodes);
    
    return best;
}
































