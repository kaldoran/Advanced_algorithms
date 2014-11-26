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




void sol(Graph g) {
	int total_node = 1, i , j, min = 0, index = -1, index2 = -1;
	Solution s = new_solution(g->count_nodes );

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

		add_node(s, g->nodes[index], 0);
		++total_node;
	}
	print_solution(s);

}
