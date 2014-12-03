//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : solution.h                                     |
// DATE : 27/10/14                                          |
//                                                          | 
// Define prototype function of tsp_mst.c                   |
// -                                                        |
//----------------------------------------------------------

#ifndef TSP_MST_H
#define TSP_MST_H

#include "solution.h"
#include "graph.h"

/**Solve the TSP with minimal spanning tree approach.
 **Build a mst with Prim's algorithm, and build the 
 **solution with a prefix course of mst.
 * %param g : complet graph
 * return 
 */
Solution MST(Graph g);


int prefix_course(Node tree, Solution s);

#endif
