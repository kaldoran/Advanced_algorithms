//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : graph.h                                        |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include "struct_graph.h"

Graph new_graph(const int number_of_node);

void free_graph(Graph g);

void print_graph(const Graph g);


#endif /* GRAPH_H included */