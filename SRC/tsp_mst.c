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
	Solution s = new_solution(g->count_nodes );						//Create solution
	Graph minimal_spanning_tree = new_graph(g->count_nodes); 		//create minimal spanning tree
	set_node(minimal_spanning_tree->nodes[0], 0, g->count_nodes);	//add root node in mst

	add_node(s, g->nodes[0], 0);									//add root node in solution;
	printf("De : Nom [Indice tableau dans S] - Nom [indice tableau dans g]\n");
	/** while we don't see all node in graph g */
	while( total_node != g->count_nodes) {
		min = INT_MAX;						//initiate min
		/** foreach node we already see */
		for ( i = 0; i < total_node;i++ ) {
			/** find minimal node cost */
			/** foreach subnodes of node[i] containing in solution */
			for ( j = 0; j < s->list_node[i]->count_subnodes; j++) {
				if (  s->list_node[i]->subnodes[j] != NULL  		//if subnode[j] exist
				  && s->list_node[i]->cost[j] < min 				//if cost of subnode[j] < min
				  && !contains(s, s->list_node[i]->subnodes[j]) ){
					min = s->list_node[i]->cost[j];
					index = j;
					index2 = i;
				}
			}

		}
		
		printf("De : %d [%d] - %d [%d]\n", s->list_node[index2]->name, index2, g->nodes[index]->name, index);

		/*minimal_spanning_tree->nodes[index2] = s->list_node[index2];
		minimal_spanning_tree->nodes[index] = g->nodes[index];
		set_node(minimal_spanning_tree->nodes[index2], s->list_node[index2]->name,g->count_nodes);
		set_node(minimal_spanning_tree->nodes[index], g->nodes[index]->name,g->count_nodes);*/

		minimal_spanning_tree->nodes[index] = new_node();
		set_node(minimal_spanning_tree->nodes[index], g->nodes[index]->name,g->count_nodes);

		/**building*/
		print_graph(minimal_spanning_tree);
		
		minimal_spanning_tree->nodes[s->list_node[index2]->name]->subnodes[g->nodes[index]->name] = minimal_spanning_tree->nodes[g->nodes[index]->name];
		minimal_spanning_tree->nodes[g->nodes[index]->name]->subnodes[s->list_node[index2]->name] = minimal_spanning_tree->nodes[s->list_node[index2]->name];
	

		add_node(s, g->nodes[index], 0);
		++total_node;
	}

	print_graph(minimal_spanning_tree);
	/*for (i = 0; i < g->count_nodes; i++) {
		if(minimal_spanning_tree->nodes[i] != NULL) {
			printf("	");
			for (j = 0; j < g->count_nodes; j++) {
				if(minimal_spanning_tree->nodes[i]->subnodes[j] != NULL ) {
					printf("De : %d - %d\n", minimal_spanning_tree->nodes[i]->name, minimal_spanning_tree->nodes[i]->subnodes[j]->name);	
				}
				
			}	
		}
	}*/

	prefix_course(minimal_spanning_tree->nodes[0]);
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
