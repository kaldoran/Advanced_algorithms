//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : solution.h                                     |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#ifndef SOLUTION_H
#define SOLUTION_H

#include "struct_solution.h"
#include "struct_graph.h"

Solution new_solution(int number_of_node);

void add_node(Solution s, Node n, int cost);

void free_solution(Solution s);

void print_solution(const Solution s);


#endif /* SOLUTION_H included */