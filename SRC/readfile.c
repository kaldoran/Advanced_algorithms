//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : readfile.h                                     |
// DATE : 25/10/14                                          |
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
     
    unsigned int i = 0, j = 0, node = 0, total_node = 0;
    char buffer[BUFFER_SIZE];

    if ((file = fopen(filename, "r")) == NULL ) {
        QUIT_MSG("Error while opening the file\n");
    }

    while(fgets(buffer, BUFFER_SIZE, file) != NULL ) {
        if ( *buffer == '$' ) {
            (void)sscanf(buffer, "$%u$", &total_node);
            tsp_graph = new_graph(total_node);
        }
        else if ( *buffer == '-' ) {
            (void)sscanf(buffer, "- %u@%u", &node, &j);

            if ( total_node != (j + 1) ) {
                free_graph(tsp_graph);
                QUIT_MSG("Sorry, the graph is not complet\n");
            }
            (void)set_node(tsp_graph->nodes[node], node, j + 1);

        }
        else if (*buffer != '\n' && *buffer != '_') {
            (void)sscanf(buffer, "%u#%u", &i, &j);

            tsp_graph->nodes[node]->subnodes[i] = tsp_graph->nodes[i];
            tsp_graph->nodes[node]->cost[i] = j;
        }
    }
        
    fclose(file);
    
    return tsp_graph;
}
