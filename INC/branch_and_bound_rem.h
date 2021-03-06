//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_rem.h                         |
// DATE : 25/11/14                                          |
//                                                          |
// - Defines prototypes function of branch_and_bound_rem.c   |
// - Function to initialise and call the algorithm          |
// - Function to run the algorithm recursively              |
//----------------------------------------------------------

#ifndef BRANCH_AND_BOUND_REM_H
#define BRANCH_AND_BOUND_REM_H

#include "struct_graph.h"
#include "edges_matrix.h"


/** Recursive function of the algorithm.
 *  %param part : Partial matrix which is compute.
 *  %param part_bound : Bound of the partial matrix.
 *  %param part_length : Number of edges used in the partial matrix.
 *  %param best : Matrix corresponding to the best path find so far.
 *  %param best_bound : Bound of the best matrix.
 *  %param best_length : Number of edges used in the best matrix.
 *  %return : matrix of the best solution found.
 */
Edges_matrix branch_and_bound_rem_rec(Edges_matrix part, int part_bound, int part_length,Edges_matrix best, int best_bound, int best_length);

/** Function initialising variables and calling the algorithm.
 *  %param tspGraph : graph needed to execute.
 *  %return : optimal solution of the tsp problem.
 */
Solution branch_and_bound_rem(Graph tspGraph);

#endif /* BRANCH_AND_BOUND_REM_H included */
