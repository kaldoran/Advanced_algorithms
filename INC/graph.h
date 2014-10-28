//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : graph.h                                        |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include "struct_graph.h"

/** Allote a graph and the space for all node [ and all node without complete them ]
 *  %param number_of_node : Number of node in the graph
 */
Graph new_graph(const int number_of_node);

/** free a graph
 *  %param g : graph to free
 */
void free_graph(Graph g);

/** Print a graph
 *  %param g : graph to print
 */
void print_graph(const Graph g);

/** Reset the coloration of all node of a graph
 *  %param g : graph to reset
 */
void reset_coloration(Graph g);


#endif /* GRAPH_H included */
