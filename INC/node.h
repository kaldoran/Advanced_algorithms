//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : node.h                                         |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#ifndef NODE_H
#define NODE_H

#include "struct_graph.h"

/** Create a new empty node
 * %return : a pointer on an empty node
 */
Node new_node();

/** Set value into a need (which already had been allocate )
 *  %param node : Node where you need to set value
 *  %param node_number : Name of the node
 *  %param number_of_subnode : Number of subnode of the node pasted into node parameter
 */
void set_node(Node node, const int node_number, const int number_of_subnode);

/** Copy a node n and return him after allocate and copy 
 *	%param n : Node to copy
 *  %return : Copy of the node n
 */
Node copy_node(const Node n);
#endif /* NODE_H included */

