#ifndef GREEDY_APPROCH_H
#define GREEDY_APPROCH_G

#include "struct_graph.h"

#define ITERATION 100

/** Execute random approch ITERATION time and give the best of all random solution
 *  %param g : graph where you need to execute the random approch
 *  %return : The best of all tested solution
 */
Solution random_approch(Graph g);

/** Execute and give the solution of random approch on a graph
 *  %param g : graph where you need to execute the random approch
 *  %param visiteColor : which is the color to use
 *  %return : A random solution
 */

Solution random_approch_compute(Graph g, int visiteColor);

#endif /* GREEDY_APPROCH_H included */
