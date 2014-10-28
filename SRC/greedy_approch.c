#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#include "struct_graph.h"


void greedy_approch(Graph g) {

	Node current = NULL;
	int i = 0, choix = 0, total_node = 0, current_mini = INT_MAX;

	printf("Ou voulez vous commencer ? Random = -1 Or [0 .. %d] ", g->count_nodes - 1);
	do {
		scanf("%d", &choix);
		if ( choix == -1 ) { choix = (char) 2; }	// Faire rand 
	} while( choix < 0 || choix > (g->count_nodes - 1) );

	current = g->nodes[choix];
	current->colored = 7;

	fprintf(stderr,"[%d] ", current->name);

	do {

		choix = -1;
		current_mini = INT_MAX;

		for ( i = 0; i < current->count_subnodes; i++) {
			if ( (current->subnodes[i]->colored != (char)1
				&& current->subnodes[i]->colored != (char) 7
				&& current->cost[i] < current_mini) 
				|| (  current->subnodes[i]->colored == (char) 7 
				&& total_node == g->count_nodes - 1 ) ) {
				
					choix = i;
					current_mini = current->cost[i];
			}
		}
		
		if ( choix != -1 ) {
			total_node++; 
			if ( current->colored != (char)7 ) {
				current->colored = (char)1;
			}
			current = current->subnodes[choix];
			fprintf(stderr,"[%d] ", current->name);
		}
		
	}while(current->colored != (char)7 && choix != -1);

	if ( total_node == g->count_nodes ) {
		printf(": Le chemin indiqué est correct\n");
	} else {
		printf(": Le chemin n'est pas passé par tout les sommets\n");
	}

	return;
}
