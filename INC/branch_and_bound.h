//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound.h                             |
// DATE : 28/10/14                                          |
//                                                          |
// - Defines prototypes function of branch_and_bound.c       |
// - Function to initialise and call the algorithm          |
// - Function to run the algorithm recursively              |
//----------------------------------------------------------

#ifndef BRANCH_AND_BOUND_H
#define BRANCH_AND_BOUND_H

#include <stdio.h>
#include <stdlib.h>

#include "solution.h"

/** Recursive function of the algorithm.
 *  %param part : partial solution which is compute.
 *  %param best : best solution find so far.
 *  %param tspGraph : graph needed to execute.
 *  %return : best solution found by the computation of part.
 */
Solution branch_and_bound_rec(Solution part, Solution best, Graph tspGraph);


/** Function initialising variables and calling the algorithm.
 *  %param tspGraph : graph needed to execute.
 *  %return : optimal solution of the tsp problem.
 */
Solution branch_and_bound(Graph tspGraph);

#endif /* BRANCH_AND_BOUND_H */
