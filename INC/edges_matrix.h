//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : edges_matrix.h                                 |
// DATE : 29/11/14                                          |
//----------------------------------------------------------


#include "struct_graph.h"
#include "solution.h"


typedef int** Edges_matrix;


/** Function to create a new empty edges matrix.
 * %param length : Number of lines/columns in the matrix.
 * %return : An empty list.
 */
Edges_matrix new_matrix(int length);

/** Function to free the memory take by an edges matrix.
 * %param matrix : Matrix to free.
 * %param length : Number of lines/columns in the matrix.
 * %return : None.
 */
void free_matrix(Edges_matrix matrix, int length);

/** Function to copy an edges matrix.
 * %param matrix : Matrix to copy.
 * %param length : Number of lines/columns in the matrix.
 * %return : Copy of the edges matrix.
 */
Edges_matrix copy_matrix(Edges_matrix matrix, int length);

/** Function to translate a graph to an edges matrix.
 * %param tspGraph : Graph to translate.
 * %return : Edges matrix corresponding to the graph.
 */
Edges_matrix graph_to_edges_matrix(Graph tspGraph);

/** Function to translate an edges matrix to a solution.
 * %param matrix : Matrix to translate.
 * %param tspGraph : Graph at the origin of the matrix.
 * %param start : Index of the starting node.
 * %return : Solution corresponding to the matrix.
 */
Solution edges_matrix_to_solution(Edges_matrix matrix, Graph tspGraph, int start);

/** Function to calculate the bound from a solution.
 * %param sol : Solution we want to compute the final bound.
 * %param matrix : Edges matrix from the graph at the origin of the solution.
 * %param matrix_end : Edges matrix resulting of the bound calculation.
 * %param length : Number of lines/columns in the matrix.
 * %return : bound calculated.
 */
int bound_solution(Solution sol, Edges_matrix matrix, Edges_matrix matrix_end, int length);

/** Function to draw an edges matrix.
 * %param matrix : Edges matrix to draw.
 * %param length : Number of lines/columns in the matrix.
 * %return : None.
 */
void print_edges_matrix(Edges_matrix matrix, int length);

/** Function to find the column index of the minimal value on a line of an edges matrix.
 * %param matrix : Edges matrix where find the value.
 * %param length : Number of lines/columns in the matrix.
 * %param index : Index of the line of the value.
 * %return : Column index of the minimale value on the line index.
 */
int index_min_line(Edges_matrix matrix, int length, int index);

/** Function to find the line index of the minimal value on a column of an edges matrix.
 * %param matrix : Edges matrix where find the value.
 * %param length : Number of lines/columns in the matrix.
 * %param index : Index of the column of the value.
 * %return : Line index of the minimale value on the column index.
 */
int index_min_col(Edges_matrix matrix, int length, int index);

/** Function to find the minimal value on a line of an edges matrix.
 * %param matrix : Edges matrix where find the value.
 * %param length : Number of lines/columns in the matrix.
 * %param index : Index of the line of the value.
 * %return : Minimale value on the line index.
 */
int min_line(Edges_matrix matrix, int length, int index);

/** Function to find the minimal value on a column of an edges matrix.
 * %param matrix : Edges matrix where find the value.
 * %param length : Number of lines/columns in the matrix.
 * %param index : Index of the column of the value.
 * %return : Minimale value on the column index.
 */
int min_col(Edges_matrix matrix, int length, int index);

/** Function to reduce the lines of an edges matrix.
 * %param matrix : Edges matrix to reduce.
 * %param matrix_red : Edges matrix reduced.
 * %param length : Number of lines/columns in the matrix.
 * %return : Bound generate by the reduction.
 */
int red_line(Edges_matrix matrix, Edges_matrix matrix_red, int length);

/** Function to reduce the columns of an edges matrix.
 * %param matrix : Edges matrix to reduce.
 * %param matrix_red : Edges matrix reduced.
 * %param length : Number of lines/columns in the matrix.
 * %return : Bound generate by the reduction.
 */
int red_col(Edges_matrix matrix, Edges_matrix matrix_red, int length);

/** Function to reduce the lines, then the columns of an edges matrix.
 * %param matrix : Edges matrix to reduce.
 * %param matrix_red : Edges matrix reduced.
 * %param length : Number of lines/columns in the matrix.
 * %return : Bound generate by the reduction.
 */
int red_all(Edges_matrix matrix, Edges_matrix matrix_red, int length);
