//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : solution.h                                     |
// DATE : 27/10/14                                          |
//															| 
//Define prototype function of tsp_mst.c 		            |
//-															|
//----------------------------------------------------------

#ifndef TSP_MST_H
#define TSP_MST_H

#include "solution.h"
#include "graph.h"

Solution tsp_mst(Graph g);

Graph build_minimal_spanning_tree(Graph g,int r);

ItemNodeSet new_ItemNodeSet();

NodeSet new_NodeSet(int length);

ItemNodeSet extract_min_cost( NodeSet node_set);

int add_NodeSet(Node* node_set, Node parent_node, int count_subnodes);