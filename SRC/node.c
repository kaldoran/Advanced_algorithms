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
    node->colored = UNVISITED;
    node->count_subnodes = number_of_subnode;
    node->subnodes = (Node*) calloc(number_of_subnode, sizeof(*node->subnodes));
    node->cost = (int *)calloc(number_of_subnode, sizeof(int));
    
    return;
}

Node copy_node(const Node n) {
    Node cp = new_node();

    cp->name = n->name;
    cp->colored = n->colored;
    cp->count_subnodes = n->count_subnodes;
    cp->subnodes = (Node*) calloc(n->count_subnodes, sizeof(*n->subnodes));
    cp->cost = (int *)calloc(n->count_subnodes, sizeof(int));

    return cp;

}
