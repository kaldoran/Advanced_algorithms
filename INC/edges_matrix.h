//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : edges_matrix.h                                 |
// DATE : 29/11/14                                          |
//----------------------------------------------------------


#include "struct_graph.h"



int** new_matrix(int length);

void free_matrix(int** matrix, int length);

int** graph_to_edges_matrix(Graph tspGraph);

int solution_to_edges_matrix(Solution sol, int** matrix, int length);

void print_edges_matrix(int** matrix, int length);

int min_line(int** matrix, int length, int index);

int min_col(int** matrix, int length, int index);

int red_line(int** matrix, int** matrix_red, int length);

int red_col(int** matrix, int** matrix_red, int length);
