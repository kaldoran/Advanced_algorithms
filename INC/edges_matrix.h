//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : edges_matrix.h                                 |
// DATE : 29/11/14                                          |
//----------------------------------------------------------


#include "struct_graph.h"
#include "solution.h"


/** Function to create a new empty edges matrix.
 * %param length : Number of lines/columns in the matrix.
 * %return : An empty list.
 */
int** new_matrix(int length);

/** Function to free the memory take by an edges matrix.
 * %param matrix : Matrix to free.
 * %param length : Number of lines/columns in the matrix.
 * %return : None.
 */
void free_matrix(int** matrix, int length);

int** copy_matrix(int** matrix, int length);

/** Function to translate a graph to a edges matrix.
 * %param tspGraph : Graph to translate.
 * %return : Edges matrix corresponding to the graph.
 */
int** graph_to_edges_matrix(Graph tspGraph);

int** solution_to_edges_matrix(Solution sol);

Solution edges_matrix_to_solution(int** matrix, int length);

/** Function to calculate the bound from a solution.
 * %param sol : Solution we want to compute the final bound.
 * %param matrix : Edges matrix from the graph at the origin of the solution.
 * %param matrix_end : Edges matrix resulting of the bound calculation.
 * %param length : Number of lines/columns in the matrix.
 * %return : bound calculated.
 */
int bound_solution(Solution sol, int** matrix, int** matrix_end, int length);

/** Function to draw an edges matrix.
 * %param matrix : Edges matrix to draw.
 * %param length : Number of lines/columns in the matrix.
 * %return : None.
 */
void print_edges_matrix(int** matrix, int length);

int index_min_line(int** matrix, int length, int index);

int index_min_col(int** matrix, int length, int index);

/** Function to find the minimal value on a line of an edges matrix.
 * %param matrix : Edges matrix where find the value.
 * %param length : Number of lines/columns in the matrix.
 * %param index : Index of the line of the value.
 * %return : Minimale value on the line index.
 */
int min_line(int** matrix, int length, int index);

/** Function to find the minimal value on a column of an edges matrix.
 * %param matrix : Edges matrix where find the value.
 * %param length : Number of lines/columns in the matrix.
 * %param index : Index of the column of the value.
 * %return : Minimale value on the column index.
 */
int min_col(int** matrix, int length, int index);

/** Function to reduce the lines of an edges matrix.
 * %param matrix : Edges matrix to reduce.
 * %param matrix_red : Edges matrix reduced.
 * %param length : Number of lines/columns in the matrix.
 * %return : Bound generate by the reduction.
 */
int red_line(int** matrix, int** matrix_red, int length);

/** Function to reduce the columns of an edges matrix.
 * %param matrix : Edges matrix to reduce.
 * %param matrix_red : Edges matrix reduced.
 * %param length : Number of lines/columns in the matrix.
 * %return : Bound generate by the reduction.
 */
int red_col(int** matrix, int** matrix_red, int length);

/** Function to reduce the lines, then the columns of an edges matrix.
 * %param matrix : Edges matrix to reduce.
 * %param matrix_red : Edges matrix reduced.
 * %param length : Number of lines/columns in the matrix.
 * %return : Bound generate by the reduction.
 */
int red_all(int** matrix, int** matrix_red, int length);
