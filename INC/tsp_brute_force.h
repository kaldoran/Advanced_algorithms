//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : tsp_brute_force.h                                        |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#ifndef TSP_BRUTE_FORCE_H
#define TSP_BRUTE_FORCE_H

#include "solution.h"
#include "graph.h"

Solution tsp_brute_force(Graph g);

Solution brute_force(Solution s, Node n, int total_node, int last_cost);


#endif /* TSP_BRUTE_FORCE_H included */