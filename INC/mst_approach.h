//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : mst_approach.h                                 |
// DATE : 21/11/14                                          |
//                                                          | 
// Define prototypes functions of mst_approach.c            |
// - function MST(Graph) to resolve TSP with MST approach.  |
// - function prefix_course(Node, Solution) to travel the   |
//   minimal spanning tree with prefix course.              |
//----------------------------------------------------------

#ifndef TSP_MST_H
#define TSP_MST_H

#include "solution.h"
#include "graph.h"

/** Solves the TSP with minimal spanning tree approach.
 ** Builds a mst with Prim's algorithm, and uses prefix-course
 ** function to build the solution.
 *  %param g : complet graph
 *  return  Solution found by MST approach
 */
Solution MST(Graph g);

/** Travels the minimal spanning tree with prefix-course.
 ** Builds solution.
 *  %param tree : root node of tree
 *  %param s : the solution which the function fill in.
 */
int prefix_course(Node tree, Solution s);

#endif /* TSP_MST_H included */
