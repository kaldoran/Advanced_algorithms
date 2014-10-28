//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : main.h                                         |
// DATE : 25/10/14                                          |
//----------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "graph.h"
#include "node.h"
#include "solution.h"
#include "readfile.h"
#include "struct_graph.h"
#include "greedy_approch.h"

/** Temporary maccro */
#define UNUSED(x) (void)(x)

int main(int argc, char const *argv[]) {
	UNUSED(argc);
    UNUSED(argv);

    Graph tsp_graph = NULL;
    
	if ( argc == 2 ) {
		tsp_graph = load(argv[1]);
		print_graph(tsp_graph);

		greedy_approch(tsp_graph);
		free_graph(tsp_graph);
		exit(EXIT_SUCCESS);
	}
	
	/*int i = -1, j;

	tsp_graph = (Graph) malloc(sizeof(*tsp_graph));
	tsp_graph->count_nodes = 0;
	tsp_graph->nodes = (Node*) calloc(10, sizeof(*tsp_graph->nodes));
     
	printf("fin creation de TSP\n");
	
	
	for( i = 0; i<10; i++) {

          Node n = (Node) calloc(1, sizeof(*n));
          n->subnodes = (Node*) calloc(10, sizeof(*n->subnodes));
          n->cost = (int *)  calloc(10, sizeof(int));
          
          n->count_subnodes = 0;
          tsp_graph->nodes[i] = n;	
		  tsp_graph->nodes[i]->name = i;
		
          for( j = 0; j<10; j++) {
                tsp_graph->nodes[i]->cost[j] = 100 + j;
                tsp_graph->nodes[i]->subnodes[j] = n;
          }
	}

     for( i = 0; i<10; i++) {
          printf("***** Node name : %d \n", tsp_graph->nodes[i]->name);
          
          for( j = 0; j<10; j++) {
                printf("\tNode Name : %d [ %d ] (%d) ", tsp_graph->nodes[i]->subnodes[j]->name, tsp_graph->nodes[i]->cost[j], tsp_graph->nodes[i]->colored);
                tsp_graph->nodes[i]->colored = (char) 1;
                printf(" [[Fun : %d]] (%d)\n", tsp_graph->nodes[i]->subnodes[j]->subnodes[i]->name, tsp_graph->nodes[i]->subnodes[i]->colored);
          }
     }
     
	for( i = 0; i<10; i++) {
          free(tsp_graph->nodes[i]->cost);
	     free(tsp_graph->nodes[i]->subnodes);
	     free(tsp_graph->nodes[i]);
	}
	
	free(tsp_graph->nodes);
	
	free(tsp_graph);*/

	exit(EXIT_SUCCESS);
}
