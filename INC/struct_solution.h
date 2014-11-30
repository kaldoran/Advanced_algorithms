//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : struct_solution.h                              |
// DATE : 27/10/14                                          |
//                                                          |
// - Define structure of solution                           |
//----------------------------------------------------------

#ifndef STRUCT_SOLUTION_H
#define STRUCT_SOLUTION_H

#include <stdio.h>
#include <stdlib.h>
#include "struct_graph.h"

typedef struct Struct_Solution {
    Node* list_node;
    int cost;
    int count_nodes_s;
}Struct_Solution;

typedef Struct_Solution* Solution;

#endif /** STRUCT_SOLUTION_H included */
