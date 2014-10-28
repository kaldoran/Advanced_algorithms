//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : struct_solution.h                              |
// DATE : 27/10/14                                          |
//                                                          |
// - Define structure of solution                           |
//----------------------------------------------------------

#ifndef STRUCT_SOLUTION_H
#define STRUCT_SOLUTION_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Struct_Solution
{
	char* list_node;
    int cost;
    long time;
}Struct_Solution;

typedef Struct_Solution* Solution;

#endif /** STRUCT_SOLUTION_H included */