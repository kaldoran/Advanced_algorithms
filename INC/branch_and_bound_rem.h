//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_rem.h                         |
// DATE : 25/11/14                                          |
//                                                          |
// - Define prototypes function of branch_and_bound_rem.c   |
// - Function to initialise and call the algorithm          |
// - Function to run the algorithm recursively              |
//----------------------------------------------------------

#include "graph.h"
#include "edges_matrix.h"


/** Recursive function of the algorithm.
 *  %param index : Index of the last node in the path.
 *  %param part : Partial matrix which is compute.
 *  %param part_bound : Bound of the partial matrix.
 *  %param part_length : Number of edges used in the partial matrix.
 *  %param best : Matrix corresponding to the best path find so far.
 *  %param best_bound : Bound of the best matrix.
 *  %param best_length : Number of edges used in the best matrix.
 *  %return : matrix of the best solution found.
 */
Edges_matrix branch_and_bound_rem_rec(int index, Edges_matrix part, int part_bound, int part_length,Edges_matrix best, int best_bound, int best_length);

/** Function initialising variables and calling the algorithm.
 *  %param tspGraph : graph needed to execute.
 *  %return : optimal solution of the tsp problem.
 */
Solution branch_and_bound_rem(Graph tspGraph);
