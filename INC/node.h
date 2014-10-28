//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : node.h                                         |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#ifndef NODE_H
#define NODE_H

#include "struct_graph.h"

Node new_node();

void set_node(Node node, const int node_number, const int number_of_subnode);

#endif /* NODE_H included */
