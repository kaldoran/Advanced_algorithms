//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_rem.h                         |
// DATE : 25/11/14                                          |
//----------------------------------------------------------

#include "graph.h"


int** branch_and_bound_rem_rec(int index, int** part, int part_bound, int part_length,int** best, int best_bound, int best_length);
Solution branch_and_bound_rem(Graph tspGraph);
