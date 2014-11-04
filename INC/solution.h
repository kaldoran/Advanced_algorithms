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

Solution new_solution();

void add_node(Solution s,const Node n, int cost);

void copy_solution( Solution dest_s, Solution src_s);

Solution best_solution( Solution* list_solution, int nb_solution);

void free_solution(Solution s);

void print_solution(const Solution s);


#endif /* SOLUTION_H included */
