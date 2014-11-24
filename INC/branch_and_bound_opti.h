//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_opti.h                             |
// DATE : 31/10/14                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "readfile.h"
#include "struct_graph.h"
#include "solution.h"


Solution branch_and_bound_rec_opti(Solution part, Solution best, Graph tspGraph);
Solution branch_and_bound_opti(Graph tspGraph);
