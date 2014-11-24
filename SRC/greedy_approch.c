#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "error.h"
#include "solution.h"
#include "graph.h"

Solution greedy_approch(Graph g) {
	Solution s;
	Node current;
	int i, choix, total_node, current_mini, start;

	s = new_solution(g->count_nodes);
	choix = 0;
	total_node = 0;
	current_mini = INT_MAX; 

	start = rand() % g->count_nodes;
	current = g->nodes[start];
	current->colored = END;
	printf("Noeud départ [%d]\n", current->name);

	do {
	
		if ( g->count_nodes == total_node - 1 ) {
			current = g->nodes[start];
			current->colored = UNVISITED;

			add_node(s, current, current->cost[choix]);
			return s;
		}

		current_mini = INT_MAX;

		for ( i = 0; i < current->count_subnodes; i++) {
			if ( (current->subnodes[i]->colored != VISITED_GREEDY
				&& current->cost[i] < current_mini) ) {
			
					choix = i;
					current_mini = current->cost[i];
			}
		}
	
		total_node++; 
		current->colored = VISITED_GREEDY;
		
		add_node(s, current, current_mini);
		s->cost += current_mini;
		current = current->subnodes[choix];
	
	}while(1); /* Never append */

	return NULL;
}

