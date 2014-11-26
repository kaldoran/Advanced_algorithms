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
	
	s = new_solution(g->count_nodes + 1); /* 2 Time the first node */
	choix = 0;
	total_node = 1;
	do {
		start = rand() % g->count_nodes;
	} while(g->nodes[start] == NULL);

	current = g->nodes[start];
	current->colored = END;
	add_node(s, current, 0); /** Add starting node */

	printf("Noeud départ [%d]\n", current->name);

	do {

		do {
			choix = rand() % current->count_subnodes;
		}while( current->subnodes[choix] == NULL 
			    || current->subnodes[choix]->colored == visiteColor
				|| current->subnodes[choix]->colored == END);
	
		++total_node; 
		add_node(s, current->subnodes[choix], current->cost[choix]);
	
		current = current->subnodes[choix];
		current->colored = visiteColor;

	}while(g->count_nodes != total_node ); /* As all graphs are complet, there is always a path from Start to End */
	g->nodes[start]->colored = visiteColor;	
	add_node(s, g->nodes[start], current->cost[start]); 		/* Weight 0 cause already add on last loop */

	return s;
}

