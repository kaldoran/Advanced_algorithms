//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : edges_matrix.c                                 |
// DATE : 29/11/14                                          |
//----------------------------------------------------------

#include <limits.h>

#include "error.h"
#include "solution.h"
#include "edges_matrix.h"


int** new_matrix(int length){
	int** matrix = (int**)calloc(length,sizeof(int*));
	int i;
	
	if(matrix == NULL){
		DEBUG_PRINTF("Can't allocate edges matrix");
		QUIT_MSG("Can't allocate edges matrix");
	}
	
	for(i = 0; i < length; ++i){
		matrix[i] = (int*)calloc(length,sizeof(int));
		if(matrix[i] == NULL){
			DEBUG_PRINTF("Can't allocate edges matrix");
			QUIT_MSG("Can't allocate edges matrix");
		}
	}
	return matrix;
}

void free_matrix(int** matrix, int length){
	int i;
	for(i = 0; i < length; ++i){
		free(matrix[i]);
	}
	free(matrix);
}

int** graph_to_edges_matrix(Graph tspGraph){
	int** matrix = new_matrix(tspGraph->count_nodes);
	int i,j;
	
	for(i = 0; i < tspGraph->count_nodes; ++i){
		for(j = 0; j < tspGraph->count_nodes; ++j){
			if(tspGraph->nodes[i]->subnodes[j] != NULL){
				matrix[i][j] = tspGraph->nodes[i]->cost[j];
			}
			else{
				matrix[i][j] = -1;
			}
		}
	}
	return matrix;	
}

int solution_to_edges_matrix(Solution sol, int** matrix, int length){
	int i,j, bound = 0;
	
	for(i = 0; i < sol->count_nodes_s; ++i){
		for(j = 0; j < length; ++j){
			if(sol->list_node[i]->subnodes[j] != NULL){
				matrix[i][j] = sol->list_node[i]->cost[j];
			}
			else{
				matrix[i][j] = -1;
			}
		}
	}
	return bound;	
}

void print_edges_matrix(int** matrix, int length){
	int i,j;
	printf("Edges matrix:\n");
	
	printf("\t\t");
	for(i = 0; i < length; ++i){
		printf("\t%d\t",i);
	}
	printf("\n\t\t");	
	for(i = 0; i < length; ++i){
		printf("+---------------");
	}
	printf("+\n");
	for(i = 0; i < length; ++i){
		printf("\t%d\t",i);
		for(j = 0; j < length; ++j){
			if(matrix[i][j] != -1){
				printf("|\t%d\t",matrix[i][j]);		
			}
			else{
				printf("|\tN\t");		
			}
		}
		printf("|\n\t\t");	
		for(j = 0; j < length; ++j){
			printf("+---------------");
		}
		printf("+\n");		
	}	
}

int min_line(int** matrix, int length, int index){
	int min = INT_MAX, j;
	
	for(j = 0; j < length; ++j){
		if(min > matrix[index][j] && matrix[index][j] != -1){
			min = matrix[index][j];
		}
	}
	
	return min;
}

int min_col(int** matrix, int length, int index){
	int min = INT_MAX, j;
	
	for(j = 0; j < length; ++j){
		if(min > matrix[j][index] && matrix[j][index] != -1){
			min = matrix[j][index];
		}
	}
	
	return min;
}

int red_line(int** matrix, int** matrix_red, int length){
	int i, j, min, bound=0;
	for(i = 0; i < length; ++i){
		min = min_line(matrix, length, i);
		bound += min;
		for(j = 0; j < length; ++j){
			if(matrix[i][j] != -1){
				matrix_red[i][j] = matrix[i][j] - min;
			}
			else{
				matrix_red[i][j] = -1;
			}
		}		
	}
	return bound;
}

int red_col(int** matrix, int** matrix_red, int length){
	int i, j, min, bound=0;
	for(j = 0; j < length; ++j){
		min = min_col(matrix, length, j);
		bound += min;
		for(i = 0; i < length; ++i){
			if(matrix[i][j] != -1){
				matrix_red[i][j] = matrix[i][j] - min;
			}
			else{
				matrix_red[i][j] = -1;
			}
		}		
	}
	return bound;
}
