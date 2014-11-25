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

#define UNVISITED 			(char) 0
#define VISITED 			(char) 1
#define VISITED_BNB 		(char) 2
#define VISITED_BRUTE_FORCE (char) 3
#define VISITED_GREEDY 		(char) 4
#define VISITED_RAND 		(char) 5
#define VISITED_MST         (char) 7
/** ATTENTION : La Plage VISITED_RAND + 1 à MAX_INT peut être prise par : 
 * 		- Genetic approch lors de la génération des Adn random 
 * 		- Random approch si le chemin n'est pas trouvé du premier coup
 */
#define END 				(char)-1

typedef struct Struct_Node
{
    int name;
    int* cost;
	char colored;
	int count_subnodes;
	struct Struct_Node** subnodes;
}Struct_Node;

typedef Struct_Node* Node;

typedef struct Struct_Graph
{
	int count_nodes;
    Node* nodes;
}Struct_Graph;

typedef Struct_Graph* Graph;

#endif /** STRUCT_GRAPH_H included */
