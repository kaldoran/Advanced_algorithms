//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : tsp_mst.c                                        |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "node.h"
#include "graph.h"

typedef struct Struct_item_node_set
{
	int cost;
	Node parent_node;
	Node node;
}Struct_item_node_set;

typedef Struct_item_node_set* ItemNodeSet;

typedef struct Struct_node_set 
{
	int size;
	ItemNodeSet* item_node;
}Struct_node_set;

typedef Struct_node_set* NodeSet;

Solution tsp_mst(Graph g) {

	int start_node = 0;
	Graph mst = NULL;

	build_minimal_spanning_tree(g,r);
}

Solution build_minimal_spanning_tree(Graph g, int r) {
	
	ItemNodeSet min_cost_item_node;
	
	Node root = g->nodes[r];
	Node spanning_tree = duplicate_node(root);
	Solution solution = new_solution();
	NodeSet node_set = new_NodeSet(g->count_nodes);

	/**start*/
	root->colored = END;
	add_solution(solution, root, 0);
	add_NodeSet(node_set, root->subnodes, root->count_subnodes);


	while (node_set->size != 0) {
		min_cost_item_node = extract_min_cost(node_set);
		
	}

	print_solution(solution);
	return solution
}

ItemNodeSet new_ItemNodeSet(){
	ItemNodeSet item_node = NULL;
	item_node = (ItemNodeSet)calloc(1, sizeof(*ItemNodeSet));
	if ( item_node == NULL ) {
        DEBUG_PRINTF("Empty item_node");
        QUIT_MSG("Can't allocate memory for a item_node");
    }

    return item_node;
}

NodeSet new_NodeSet(int length) {
	NodeSet node_set = NULL;

	node_set = (NodeSet) calloc(1, sizeof(*NodeSet));
	if ( node_set == NULL ) {
        DEBUG_PRINTF("Empty node_set");
        QUIT_MSG("Can't allocate memory for a node_set");
    }

    node_set->item_node = (ItemNodeSet*) calloc(length, sizeof(ItemNodeSet));
	if ( node_set == NULL ) {
        DEBUG_PRINTF("Empty node_set->nodes");
        QUIT_MSG("Can't allocate memory for a node_set->nodes");
    }

    for( i = 0; i < length; i++) {
    	node->item_node[i] = new_ItemNodeSet();
    }

    node_set->size = 0;

    return node_set;
}

ItemNodeSet extract_min_cost( NodeSet node_set) {
	int i = 0;
	int j = 0;
	int min_cost = 32 767; // max value of int
	ItemNodeSet min_cost_item_node = NULL;

	while ( j < node_set->size) {
		if(node_set->item_node[i]->node != NULL) {
			if(node_set->item_node[i]->cost <= min) {
				min = node_set->item_node[i]->cost;
				min_cost_item_node = node_set->item_node[i];
				++j;
			}
		}
		++i;
	}
	--node_set->size;
	min_cost_item_node->node->colored = VISITED;

	return min_cost_item_node;
}

int add_NodeSet(Node* node_set, Node parent_node, int count_subnodes) {
	int i = 0;
	int number_of_node_added = 0;

	if(node_set->nodes == NULL) {
		fprintf(stderr, "add_NodeSet : Empty node_set->nodes\n", );
		return -1;
	}

	if(parent_node == NULL) {
		fprintf(stderr, "add_NodeSet : Empty parent_node\n", );
		return -1;
	}

	if( parent_node->subnodes == NULL) {
		fprintf(stderr, "add_NodeSet : Empty subnodes\n", );
		return -1;
	}

	if(count_subnodes<=0) {
		fprintf(stderr, "add_NodeSet : bad count_subnodes\n", );
		return -1;
	}

	for( i = 0; i < count_subnodes; i++) {
		if(		parent_node->subnodes[i] != NULL 
			&& 	node_set->item_node[i]->node == NULL ) {

			if(parent_node->subnodes[i]->colored == UNVISITED) {
				node_set->item_nodes[i]->node = parent_node->subnodes[i];
				node_set->item_node[i]->parent_node = parent_node;
				node_set->item_node[i]->cost = parent_node->cost[i];
				node_set->item_node[i]->node->colored = UNVISITED;
				++node_set->size;
				++number_of_node_added;
			}
		
		}
	}

	return number_of_node_added;
}

