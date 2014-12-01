//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : tsp_brute_force.h                              |
// DATE : 27/10/14                                          |
//                                                          |
//  - Functions that resolve TSP with brute-force approach  |
//----------------------------------------------------------

#ifndef TSP_BRUTE_FORCE_H
#define TSP_BRUTE_FORCE_H

#include "solution.h"
#include "graph.h"

/** Execute and give the solution of brute-force approach on a graph
 *  %param g : graph where you need to execute the greedy approch
 *  %return : solution type Solution (report to solution.h struct_solution.h)
 */
Solution tsp_brute_force(Graph g);


/** Execute the recursive algorithm of brute-force approach
 *  %param s : current incompleted solution, the function complete this solution.
 *  %param n : current node where you need to execute the brute-force approach
 *  %param total_node : size of graphe, the function determine if solution s is 
 *                        complete with this paramater.
 *  %param last_cost : the cost of edge between last node and the current node.
 *  %return : solution type Solution (report to solution.h struct_solution.h).  
 */
Solution brute_force(Solution s, Node n, int total_node, int last_cost);


#endif /* TSP_BRUTE_FORCE_H included */