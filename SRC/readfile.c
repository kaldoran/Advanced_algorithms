//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : readfile.h                                     |
// DATE : 27/10/14                                          |
//                                                          |
// - Read a file give in input                              |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "readfile.h"

#include "graph.h"
#include "node.h"

#define BUFFER_SIZE 1024

Graph load(const char *filename) {

	FILE *file;
    Graph tsp_graph = NULL;
     
	unsigned int i = 0, j = 0, node = 0, number_of_subnode = 0;
	char buffer[BUFFER_SIZE];

	if ((file = fopen(filename, "r")) == NULL ) {
		QUIT_MSG("Error while opening the file\n");
	}

	while(fgets(buffer, BUFFER_SIZE, file) != NULL ) {
		if ( *buffer == '$' ) {
			(void)sscanf(buffer, "$%u$", &i);
			printf("Number of Node : %u\n", i);
			tsp_graph = new_graph(i);
		}
		else if ( *buffer == '-' ) {
			(void)sscanf(buffer, "- %u@%u", &node, &number_of_subnode);
			printf("Node : %u - Number of Subnode : %u\n", node, number_of_subnode);
			(void)set_node(tsp_graph->nodes[node], node, number_of_subnode);
		}
		else if (*buffer != '\n' && *buffer != '_') {
			(void)sscanf(buffer, "%u#%u", &i, &j);
			printf("\tSubnode : %u - Weight: %u\n", i, j);

			tsp_graph->nodes[node]->subnodes[--number_of_subnode] = tsp_graph->nodes[i];
			tsp_graph->nodes[node]->cost[number_of_subnode] = j;
		}
	}
		
	fclose(file);
	
	return tsp_graph;
}
