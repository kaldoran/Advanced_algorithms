//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : tsp_mst.c                                      |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"
#include "node.h"
#include "graph.h"
#include "solution.h"
#include "tsp_mst.h"


Solution MST(Graph g) {
    int total_node = 1, i , j, min = 0, index = -1, index2 = -1;
    Solution s = new_solution(g->count_nodes);    
    Solution optimal_solution = new_solution(g->count_nodes);                      //Create solution
    Graph minimal_spanning_tree = new_graph(g->count_nodes);                       //create minimal spanning tree
    set_node(minimal_spanning_tree->nodes[0], 0, g->count_nodes);                  //add root node in mst

    add_node(s, g->nodes[0], 0);                                                   //add root node in solution;

    /** while we don't see all node in graph g */
    while( total_node != g->count_nodes) {
        min = INT_MAX;                                                             //initiate min
        /** foreach node we already see */
        for ( i = 0; i < total_node; i++ ) {
            /** find minimal node cost */
            /** foreach subnodes of node[i] containing in solution */
            for ( j = 0; j < s->list_node[i]->count_subnodes; j++) {
                if (  s->list_node[i]->subnodes[j] != NULL                         //if subnode[j] exist
                  && s->list_node[i]->cost[j] < min                                //if cost of subnode[j] < min
                  && !contains(s, s->list_node[i]->subnodes[j]) ){
                    min = s->list_node[i]->cost[j];
                    index = j;
                    index2 = i;
                }
            }

        }
        

        set_node(minimal_spanning_tree->nodes[index], g->nodes[index]->name,g->count_nodes);

        /**building*/
        minimal_spanning_tree->nodes[s->list_node[index2]->name]->subnodes[g->nodes[index]->name] = minimal_spanning_tree->nodes[g->nodes[index]->name];

        add_node(s, g->nodes[index], 0);
        ++total_node;
    }

    prefix_course(minimal_spanning_tree->nodes[0], optimal_solution);
    add_node(optimal_solution, copy_node(minimal_spanning_tree->nodes[0]), 0);

    cost_solution( g, optimal_solution);
    /** free all alloc */
    free_solution(s);
    free_graph(minimal_spanning_tree);
    return optimal_solution;
}


int prefix_course(Node tree, Solution s) {
    int i = 0;
    tree->colored = VISITED;
    add_node(s,copy_node(tree), 0);
    for( i = 0; i < tree->count_subnodes; i++) {
        if(tree->subnodes[i] != NULL) {
            prefix_course(tree->subnodes[i], s);
        }
    }

    return 1;
}

