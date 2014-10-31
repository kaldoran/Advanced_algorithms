#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "error.h"
#include "solution.h"
#include "graph.h"

void greedy_approch(Graph g) {
	Solution s;
	Node current;
	int i, j, choix, total_node, current_mini, poids;

	for ( j = 0; j < g->count_nodes; j++) {
		s = new_solution();
		choix = 0;
		total_node = 0;
		current_mini = INT_MAX; 
		poids = 0;

		current = g->nodes[j];
		current->colored = END;
		printf("Noeud départ [%d]\n", current->name);

		do {

			choix = -1;
			current_mini = INT_MAX;

			for ( i = 0; i < current->count_subnodes; i++) {
				if ( (current->subnodes[i]->colored != VISITED
					&& current->subnodes[i]->colored != END
					&& current->cost[i] < current_mini) 
					|| (  current->subnodes[i]->colored == END
					&& total_node == g->count_nodes - 1 ) ) {
				
						choix = i;
						current_mini = current->cost[i];
				}
			}
		
			if ( choix != -1 ) {
				total_node++; 
				if ( current->colored != END ) {
					current->colored = VISITED;
				}

				DEBUG_PRINTF("[%d] ", current->name);
				add_node(s, current, current_mini);
				poids += current_mini;
				current = current->subnodes[choix];
			}

		}while(current->colored != END && choix != -1);

		DEBUG_PRINTF("[%d]", current->name);
		add_node(s, current, 0);

		if ( total_node == g->count_nodes ) {
			print_solution(s);
		} else { 
			printf("No solution available from this node\n");
		}

		free_solution(s);
		reset_coloration(g);		
	}
	return;
}

