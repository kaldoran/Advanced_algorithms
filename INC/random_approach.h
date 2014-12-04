//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : random_approach.h                              |
// DATE : 27/10/14                                          |
//                                                          |
// - Implemente prototype of random approach                |
//----------------------------------------------------------

#ifndef GREEDY_APPROCH_H
#define GREEDY_APPROCH_G

#include "struct_graph.h"

/** Execute random approach ITERATION time and give the best of all random solution
 *  %param g : graph where you need to execute the random approch
 *  %return : The best of all tested solution
 */
Solution random_approach(Graph g);

/** Execute and give the solution of random approach on a graph
 *  %param g : graph where you need to execute the random approch
 *  %param visiteColor : which is the color to use
 *  %return : A random solution
 */

Solution random_approach_compute(Graph g, int visiteColor);

#endif /* GREEDY_APPROCH_H included */
