//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : node.c                                         |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "node.h"

Node new_node() {

    Node n = (Node) calloc(1, sizeof(*n));
    if ( n == NULL ) {
        DEBUG_PRINTF("Empty Node");
    }
    
    return n;
}


void set_node(Node node, const int node_number, const int number_of_subnode) {
   
    node->name = node_number;
    node->count_subnodes = number_of_subnode;
    node->subnodes = (Node*) calloc(number_of_subnode, sizeof(*node->subnodes));
    node->cost = (int *)calloc(number_of_subnode, sizeof(int));
	
	return;
}
