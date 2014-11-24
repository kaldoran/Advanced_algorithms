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
	int start, choix, total_node;
	srand (time(NULL));
	
	s = new_solution(g->count_nodes);
	choix = 0;
	total_node = 0;
	
	start = rand() % g->count_nodes;

	current = g->nodes[start];
	current->colored = END;

	printf("Noeud départ [%d]\n", current->name);

	do {
		if ( g->count_nodes == total_node - 1 ) {
			current = g->nodes[start];
			current->colored = UNVISITED;

			add_node(s, g->nodes[start], g->nodes[start]->cost[choix]); /* Weight from A to B is same a from B to A */
			return s;
		}
		
		do {
			choix = rand() % current->count_subnodes;
		}while(current->subnodes[choix]->colored == visiteColor);
	
		total_node++; 
		current->colored = visiteColor;
		
		DEBUG_PRINTF("[%d] ", current->name);
		add_node(s, current, current->cost[choix]);
		s->cost += current->cost[choix];
		current = current->subnodes[choix];
	
		
	}while(1); /* As all graphs are complet, there is always a path from Start to End */

	return NULL; /* Never append, complet graph */
}

