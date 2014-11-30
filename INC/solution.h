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
Solution new_solution(const int count_nodes_s);

/** Adding a node and this cost in solution and calculate automatically
 ** the new cost of solution.
 *  %param s : the solution which the function adding node n
 *	%param n : node which the function adding in solution s
 *	%param cost : the cost of edge between last node and the current node
 */
void add_node(Solution s,const Node n, int cost);

/** Allocate a solution and copie src_s into it
 *  %param src_s : original solution
 *  %return : copy of the src_s solution
 */
Solution copy_solution( Solution src_s);

/** Calculating the best solution from a list of solution and return the id of the best solution
 *  %param list_solution :  a list of solution
 *  %param nb_solution : number of solution in the list of solution
 *  %return : the id of the best solution
 */
int best_solution_id( Solution* list_solution, int nb_solution);

/** free all solution allocations
 * %param s : the solution which you will free
 */
void free_solution(Solution s);

void free_solution_bis(Solution s);

/** Printing all contains of solution
 *  %param s : the solution which you will print
 */
void print_solution(const Solution s);

/** Calculate the cost of the solution s
 *  %param s : Solution which on you need to calculate the cost
 */
void cost_solution(const Solution s);

/** Test is the solution S containe the node N
 *  %param s : Solution to test
 *  %param n : Node to test
 *  %return  : 1 If S contains n
 *  		   else 0
 */
int contains(Solution s, Node n); 

#endif /* SOLUTION_H included */
