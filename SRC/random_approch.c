#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "global.h"
#include "error.h"
#include "solution.h"
#include "graph.h"

void random_approch(Graph g) {
	Solution s;
	Node current;
	int j, choix, total_node, poids;
	srand (time(NULL));
	
	j = 0;
	do {
		s = new_solution();

		total_node = 0;
		poids = 0;
		
		choix = rand() % g->count_nodes;

		current = g->nodes[choix];
		current->colored = END;


		printf("Noeud départ [%d]\n", current->name);

		do {

			choix = -1;
			/* Check if one is available */
			for ( j = 0; j < current->count_subnodes && current->subnodes[j]->colored == VISITED; j++ ) ;

			if ( j == current->count_subnodes && current->subnodes[--j]->colored == VISITED ) { 
				break;
			}

			do {
				choix = rand() % current->count_subnodes;
			}while(current->subnodes[choix]->colored == VISITED);

			if ( choix != -1 ) {
				total_node++; 
				if ( current->colored != END ) {
					current->colored = VISITED;
				}

				DEBUG_PRINTF("[%d] ", current->name);
				add_node(s, current, current->cost[choix]);
				poids += current->cost[choix];
				current = current->subnodes[choix];
			}

		}while(current->colored != END && choix != -1);

		if ( choix != - 1 ) {
			DEBUG_PRINTF("[%d]", current->name);
			add_node(s, current, 0);

			if ( total_node == g->count_nodes ) {
				print_solution(s);
				return;
			} else { 
				printf("No solution available from this node\n");
			}
		}

		free_solution(s);
		reset_coloration(g);		
	}while(1);
	return;
}

