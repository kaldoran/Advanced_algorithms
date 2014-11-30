//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_rem.h                         |
// DATE : 25/11/14                                          |
//----------------------------------------------------------

#include "graph.h"
#include "edges_matrix.h"

Edges_matrix branch_and_bound_rem_rec(int index, Edges_matrix part, int part_bound, int part_length,Edges_matrix best, int best_bound, int best_length);
Solution branch_and_bound_rem(Graph tspGraph);
