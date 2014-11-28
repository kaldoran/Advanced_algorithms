//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : graph.c                                        |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "node.h"
#include "graph.h"

Graph new_graph(const int number_of_node) {

    int i = 0;
    Graph tsp_graph = NULL;
    
    tsp_graph = (Graph) calloc(1, sizeof(*tsp_graph));
    
    if ( tsp_graph == NULL ) {
        DEBUG_PRINTF("Empty Graph");
        QUIT_MSG("Can't allocate memory for a graph");
    }
    
    tsp_graph->count_nodes = number_of_node;
    
    tsp_graph->nodes = (Node*) calloc(number_of_node, sizeof(*tsp_graph->nodes));
    
    if ( tsp_graph->nodes == NULL ) {
        free(tsp_graph);
        DEBUG_PRINTF("Empty array of node");
        QUIT_MSG("Can't allocate memory for array of node");
    }
    
    for ( i = 0; i < number_of_node; i++ ) {
        tsp_graph->nodes[i] = new_node();
        
        if ( tsp_graph->nodes[i] == NULL ) {
            free(tsp_graph->nodes);
            free(tsp_graph);
            QUIT_MSG("Can't allocate memory for a new node");
        }
    }
    
    return tsp_graph;         
}


void free_graph(Graph g) {
    int i = 0;

	for( i = 0; i < g->count_nodes; i++) {
         free(g->nodes[i]->cost);
	     free(g->nodes[i]->subnodes);
	     free(g->nodes[i]);
	}
	
	free(g->nodes);
	
	free(g);

	return;
}


void print_graph(const Graph g) {
    int i = 0, j = 0;
    
    printf("\nPrint the graph : \n");
    
    for( i = 0; i < g->count_nodes; i++) {
        printf("***** Node name : %d \n", g->nodes[i]->name);
          
        for( j = 0; j < g->nodes[i]->count_subnodes; j++) {
			if (g->nodes[i]->subnodes[j] != NULL) {
           		printf("\tNode Name : %d [ %d ] (%d)\n", g->nodes[i]->subnodes[j]->name, g->nodes[i]->cost[j], g->nodes[i]->colored);
			}
        }
    }

	return;
}


void reset_coloration(Graph g) {
	int i;
	for ( i = 0; i < g->count_nodes; i++ ) {
		g->nodes[i]->colored = UNVISITED;
	}

	return;
}
