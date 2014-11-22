#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "global.h"
#include "error.h"
#include "solution.h"
#include "graph.h"

Solution random_approch(Graph g, int visiteColor) {
	Solution s;
	Node current;
	int start, j, choix, total_node, poids;
	srand (time(NULL));
	
	j = 0;
	do {
		s = new_solution(g->count_nodes);

		total_node = 0;
		poids = 0;
		
		start = rand() % g->count_nodes;

		current = g->nodes[start];
		current->colored = END;


		printf("Noeud départ [%d]\n", current->name);

		do {

			choix = -1;
			/* Check if one is available */
			for ( j = 0; j < current->count_subnodes && current->subnodes[j]->colored == Visite_Color; j++ ) ;

			if ( j == current->count_subnodes && current->subnodes[--j]->colored == Visite_Color ) { 
				break;
			}

			do {
				choix = rand() % current->count_subnodes;
			}while(current->subnodes[choix]->colored == Visite_Color);

			if ( choix != -1 ) {
				total_node++; 
				if ( current->colored != END ) {
					current->colored = Visite_Color;
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
				g->nodes[start] = UNVISITED;
				print_solution(s);
				return s;
			} else { 
				printf("No solution available from this node\n");
				++Visite_Color;
			}
		}
		
		g->nodes[start] = UNVISITED;
		free_solution(s);	
	}while(1);

	return NULL; /* Never append */
}

