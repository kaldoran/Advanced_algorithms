//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound.c                             |
// DATE : 28/10/14                                          |
//----------------------------------------------------------

#include "branch_and_bound.h"

char isInTab(int n, int* tab, int l) {
	int i;
	for(i =0; i < l; ++i){
		if(n == tab[i]){
			return 1;
		}
	}
	return 0;
}

bnb branch_and_bound_rec(bnb part, bnb best, Graph tspGraph) {
	int cost = 0, k;
	if(part->n == best->n -1){
		k=0;
		while(tspGraph->nodes[part->p[0]]->subnodes[k]->name != tspGraph->nodes[part->p[part->n-1]]->name) {
			++k;
		}
		cost = part->w + tspGraph->nodes[part->p[0]]->cost[k];
		if(cost < best->w) {
			for(k = 0; k < part->n; ++k) {
				best->p[k] = part->p[k];
			}
			best->p[part->n] = part->p[0];
			best->w = cost;	
		}
	}
	else{
		int j;
		for(j=0; j < tspGraph->count_nodes; ++j) {
			if(!isInTab(j, part->p, part->n)) {
				k=0;
				while(tspGraph->nodes[part->p[part->n-1]]->subnodes[k]->name != j) {
					++k;
				}
				cost = part->w + tspGraph->nodes[part->p[part->n-1]]->cost[k];
				if(cost < best->w) {
					bnb newPart = (bnb)malloc(sizeof(*newPart));
					newPart->n = part->n +1;
					newPart->w = cost;
					newPart->p = part->p;
					newPart->p[part->n] = j;
					best = branch_and_bound_rec(newPart, best, tspGraph);
				}
			}
		}
	}
	return best;
}

int branch_and_bound(Graph tspGraph) {
	int start = 0;
	int i, j = 1;
	Node current = NULL;

	bnb part = (bnb)malloc(sizeof(*part));
	part->n = 1;
	part->w = 0;
	part->p = (int*)calloc(tspGraph->count_nodes, sizeof(int));
	part->p[0] = start;

	bnb best = (bnb)malloc(sizeof(*best));
	best->n = tspGraph->count_nodes;
	best->w = 0;
	best->p = (int*)calloc(tspGraph->count_nodes, sizeof(int));
	best->p[0] = start;
	tspGraph->nodes[start]->colored = END;
	current = tspGraph->nodes[start];

	while(j < tspGraph->count_nodes) {
		for(i = 0; i < current->count_subnodes; ++i) {
			if(current->subnodes[i]->colored == UNVISITED) {
				best->p[j] = current->subnodes[i]->name;
				current->subnodes[i]->colored = VISITED;
				best->w += current->cost[i];
				current = current->subnodes[i];
				++j;
			}		
		}
	}
	best-> p[j] = tspGraph->nodes[start]->name;
	++best->n;
	i=0;
	while(current->subnodes[i]->name != start){
		++i;
	}
	best->w += current->cost[i];

	for(i = 0; i < best->n -1; ++i) {
		printf("%d - ", best->p[i]);
	}
	printf("%d weight: %d\n", best->p[i], best->w);

	bnb bst = branch_and_bound_rec(part, best, tspGraph);

	for(i = 0; i < bst->n -1; ++i) {
		printf("%d - ", bst->p[i]);
	}
	printf("%d weight: %d\n", bst->p[i], bst->w);
	
	return EXIT_SUCCESS;
}