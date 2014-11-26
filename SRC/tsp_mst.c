//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : tsp_mst.c                                        |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"
#include "node.h"
#include "graph.h"
#include "solution.h"
#include "tsp_mst.h"


void MST(Graph g) {
	int total_node = 1, i , j, min = 0, index = -1, index2 = -1;
	Solution s = new_solution(g->count_nodes );
	Node minimal_spanning_tree = new_graph(g->count_nodes);

	add_node(s, g->nodes[0], 0);
	
	while( total_node != g->count_nodes) {
		for ( i = 0; i < total_node;i++ ) {
			min = INT_MAX;
			for ( j = 0; j < s->list_node[i]->count_subnodes; j++) {
				if (  s->list_node[i]->subnodes[j] != NULL 
				  && s->list_node[i]->cost[j] < min 
				  && !contains(s, s->list_node[i]->subnodes[j]) ){
					min = s->list_node[i]->cost[j];
					index = j;
					index2 = i;
				}
			}

		}
		
		printf("De : %d - %d\n", index2, index);
		/**create the node number index2 if it doesn't exist*/
		if(minimal_spanning_tree->nodes[index2] == NULL) {
			minimal_spanning_tree->nodes[index2] = new_node();
			set_node(minimal_spanning_tree->nodes[index2], index2,g->count_nodes);	
		}
		
		/**create the node number index if it doesn't exist*/
		if(minimal_spanning_tree->nodes[index] == NULL ) {
			minimal_spanning_tree->nodes[index] = new_node();
			set_node(minimal_spanning_tree->nodes[index], index,g->count_nodes);	
		}

		/**building*/
		minimal_spanning_tree->nodes[index2]->subnodes[index] = minimal_spanning_tree->nodes[index];
		minimal_spanning_tree->nodes[index]->subnodes[index2] = minimal_spanning_tree->nodes[index2];

		for (i = 0; i < g->count_nodes; i++)
		{
			if(minimal_spanning_tree->nodes[i] != NULL) {
				printf("	");
				for (j = 0; j < g->count_nodes; j++) {
					if()
					printf("De : %d - %d\n", minimal_spanning_tree->nodes[i], minimal_spanning_tree->nodes[i]);
				}	
			}
			
		}
		add_node(s, g->nodes[index], 0);
		++total_node;
	}
	print_solution(s);

}
