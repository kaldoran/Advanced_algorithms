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
	if(part->nbNodes == best->nbNodes -1){
		k=0;
		while(tspGraph->nodes[part->path[0]]->subnodes[k]->name != tspGraph->nodes[part->path[part->nbNodes-1]]->name) {
			++k;
		}
		cost = part->weight + tspGraph->nodes[part->path[0]]->cost[k];
		if(cost < best->weight) {
			for(k = 0; k < part->nbNodes; ++k) {
				best->path[k] = part->path[k];
			}
			best->path[part->nbNodes] = part->path[0];
			best->weight = cost;	
		}
	}
	else{
		int j;
		for(j=0; j < tspGraph->count_nodes; ++j) {
			if(!isInTab(j, part->path, part->nbNodes)) {
				k=0;
				while(tspGraph->nodes[part->path[part->nbNodes-1]]->subnodes[k]->name != j) {
					++k;
				}
				cost = part->weight + tspGraph->nodes[part->path[part->nbNodes-1]]->cost[k];
				if(cost < best->weight) {
					bnb newPart = (bnb)malloc(sizeof(*newPart));
					/* Tu as pas testé le retour ^^ */
					newPart->nbNodes = part->nbNodes +1;
					newPart->weight = cost;
					newPart->path = part->path;
					newPart->path[part->nbNodes] = j;
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
	/* La non plus le retour est pas testé */
	part->nbNodes = 1;
	part->weight = 0;
	part->path = (int*)calloc(tspGraph->count_nodes, sizeof(int));
	/* Pas testé */
	part->path[0] = start;

	bnb best = (bnb)malloc(sizeof(*best));
	best->nbNodes = tspGraph->count_nodes;
	best->weight = 0;
	best->path = (int*)calloc(tspGraph->count_nodes, sizeof(int));
	/* Pas testé */
	best->path[0] = start;
	tspGraph->nodes[start]->colored = END;
	current = tspGraph->nodes[start];

	while(j < tspGraph->count_nodes) {
		for(i = 0; i < current->count_subnodes; ++i) {
			if( current->subnodes[i] != NULL
			 && current->subnodes[i]->colored == UNVISITED) {
				best->path[j] = current->subnodes[i]->name;
				current->subnodes[i]->colored = VISITED_BNB;
				best->weight += current->cost[i];
				current = current->subnodes[i];
				++j;
			}		
		}
	}
	best->path[j] = tspGraph->nodes[start]->name;
	++best->nbNodes;
	i=0;
	while(current->subnodes[i]->name != start){
		++i;
	}
	best->weight += current->cost[i];

	for(i = 0; i < best->nbNodes -1; ++i) {
		printf("%d - ", best->path[i]);
	}
	printf("%d weight: %d\n", best->path[i], best->weight);

	bnb bst = branch_and_bound_rec(part, best, tspGraph);

	for(i = 0; i < bst->nbNodes -1; ++i) {
		printf("%d - ", bst->path[i]);
	}
	printf("%d weight: %d\n", bst->path[i], bst->weight);

	return EXIT_SUCCESS;
}
