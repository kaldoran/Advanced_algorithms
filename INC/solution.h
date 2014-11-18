//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : solution.h                                     |
// DATE : 27/10/14                                          |
//															| 
//Define prototype function of solution.c 		            |
//-function to create a empty solution    					|
//-function to add a node in solution 						|
//-function to copy(to duplicate) a solution 				|
//-function to return the best solution into list of 		|
// solutions												|
//-function to free solution allocation 					|
//-funtion to print Solution 								|
//----------------------------------------------------------

#ifndef SOLUTION_H
#define SOLUTION_H

#include "struct_solution.h"
#include "struct_graph.h"


/** Creating a empty solution and doing all necessary allocation
 *  %param : none
 *  %return : none
 */
Solution new_solution();

/** Adding a node and this cost in solution and calculate automatically
 ** the new cost of solution.
 *  %param s : the solution which the function adding node n
 *	%param n : node which the function adding in solution s
 *	%param cost : the cost of edge between last node and the current node
 *  %return : none
 */
void add_node(Solution s,const Node n, int cost);

/**Duplicating a solution
 * %param dest_s : the copied solution
 * %param src_s : original solution
 * %return : none
 */
void copy_solution( Solution dest_s, Solution src_s);

/**Calculating the best solution from a list of solution
 * %param list_solution :  a list of solution
 * %param nb_solution : number of solution in the list of solution
 * %return : the best Solution
 */
Solution best_solution( Solution* list_solution, int nb_solution);

/** free all solution allocations
 * %param s : the solution which you will free
 * %return : none
 */
void free_solution(Solution s);

/**Printing all contains of solution
 * %param s : the solution which you will print
 * %return : none
 */
void print_solution(const Solution s);


#endif /* SOLUTION_H included */
