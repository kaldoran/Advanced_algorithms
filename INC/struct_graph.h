//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : struct_graph.h                                 |
// DATE : 27/10/14                                          |
//                                                          |
// - Define structure of graph                              |
// - Define structure of node of the graph                  |
//----------------------------------------------------------

#ifndef STRUCT_GRAPH_H
#define STRUCT_GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Struct_Node
{
    char name;
    char* cost;
	char colored;
	char count_subnodes;
	struct Struct_Node** subnodes;
}Struct_Node;

typedef Struct_Node* Node;

typedef struct Struct_Graph
{
	char count_nodes;
    Node* nodes;
}Struct_Graph;

typedef Struct_Graph* Graph;

#endif /** STRUCT_GRAPH_H included */