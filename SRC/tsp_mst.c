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
	Graph minimal_spanning_tree = new_graph(g->count_nodes);
	set_node(minimal_spanning_tree->nodes[0], 0, g->count_nodes);

	add_node(s, g->nodes[0], 0);
	printf("De : Nom [Indice tableau dans S] - Nom [indice tableau dans g]");
	while( total_node != g->count_nodes) {
		min = INT_MAX;
		for ( i = 0; i < total_node;i++ ) {
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
		
		printf("De : %d [%d] - %d [%d]\n", s->list_node[index2]->name, index2, s->list_node[index]->name, index);
		set_node(minimal_spanning_tree->nodes[index2], index2,g->count_nodes);	
		set_node(minimal_spanning_tree->nodes[index], index,g->count_nodes);	

		/**building*/
		minimal_spanning_tree->nodes[index2]->subnodes[index] = minimal_spanning_tree->nodes[index];
		minimal_spanning_tree->nodes[index]->subnodes[index2] = minimal_spanning_tree->nodes[index2];


		add_node(s, g->nodes[index], 0);
		++total_node;
	}

	/*for (i = 0; i < g->count_nodes; i++) {
		if(minimal_spanning_tree->nodes[i] != NULL) {
			printf("	");
			for (j = 0; j < g->count_nodes; j++) {
				if(minimal_spanning_tree->nodes[i]->subnodes[j] != NULL ) {
					printf("De : %d - %d\n", minimal_spanning_tree->nodes[i]->name, minimal_spanning_tree->nodes[i]->subnodes[j]->name);	
				}
				
			}	
		}
	}

	prefix_course(minimal_spanning_tree->nodes[0]);*/
}


void prefix_course(Node tree) {
	int i = 0;
	if(tree != NULL) {
		tree->colored = VISITED;
		printf("Name : %d\n",tree->name);getchar();
		for( i = 0; i < tree->count_subnodes; i++) {
			if(tree->subnodes[i] != NULL) {
				if(tree->subnodes[i]->colored != VISITED) {
					printf("Entrer dans l'itération [%d] du sommet %d: \n",i, tree->name);
					prefix_course(tree->subnodes[i]);
				}
			}
		}
		//printf("feuille : %d\n",tree->subnodes[i] );
	}
}
