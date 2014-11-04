//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound.h                             |
// DATE : 31/10/14                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "readfile.h"
#include "struct_graph.h"

typedef struct structBnb {
	int nbNodes;
	int weight;
	int* path;
} bnbStruct;

typedef bnbStruct* bnb;

char isInTab(int n, int* tab, int l);
bnb branch_and_bound_rec(bnb part, bnb best, Graph tspGraph);
int branch_and_bound(Graph tspGraph);