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


Solution MST(Graph g) {
	int total_node = 1, i , j, min = 0, index = -1, index2 = -1;
	Solution s = new_solution(g->count_nodes );	
	Solution optimal_solution = new_solution(g->count_nodes+1);					//Create solution
	Graph minimal_spanning_tree = new_graph(g->count_nodes+1); 		//create minimal spanning tree
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

	
	/*	minimal_spanning_tree->nodes[index] = new_node();*/
		set_node(minimal_spanning_tree->nodes[index], g->nodes[index]->name,g->count_nodes);

		/**building*/
		minimal_spanning_tree->nodes[s->list_node[index2]->name]->subnodes[g->nodes[index]->name] = minimal_spanning_tree->nodes[g->nodes[index]->name];
		//minimal_spanning_tree->nodes[g->nodes[index]->name]->subnodes[s->list_node[index2]->name] = minimal_spanning_tree->nodes[s->list_node[index2]->name];
		add_node(s, g->nodes[index], 0);
		++total_node;
	}

	prefix_course(minimal_spanning_tree->nodes[0], optimal_solution,1);
	add_node(optimal_solution,copy_node(minimal_spanning_tree->nodes[0]),0 );
	for(i = 0; i < optimal_solution->count_nodes_s-1 ; i++) {
		optimal_solution->cost += g->nodes[optimal_solution->list_node[i]->name]->cost[optimal_solution->list_node[i+1]->name];
	}
	/** free all alloc */
	free_solution(s);
	free_graph(minimal_spanning_tree);
	return optimal_solution;
}


int prefix_course(Node tree, Solution s, int state) {
	int i = 0;
	tree->colored = VISITED;
	add_node(s,copy_node(tree),0);
	for( i = 0; i < tree->count_subnodes; i++) {
		if(tree->subnodes[i] != NULL) {
			state = prefix_course(tree->subnodes[i],s,state);
		}
	}

	return 1;
}

