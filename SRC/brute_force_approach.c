//--------------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                     |
// FICHIER : brute_force_approach.c                             |
// DATE : 15/11/14                                              |
//                                                              |
// - Implementation of the prototypes in brute_force_approach.h |
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "error.h"
#include "brute_force_approach.h"
#include "graph.h"
#include "solution.h"
#include "node.h"


Solution brute_force_approach(Graph g) {

    Solution tsp_final_solution = NULL;

    if ( g == NULL) {
        return tsp_final_solution;
    }

    tsp_final_solution = new_solution(g->count_nodes);

    if ( g->count_nodes == 1) {
        add_node(tsp_final_solution, g->nodes[0], 0);
        return tsp_final_solution;
    }

    if ( g->count_nodes == 2) {
        add_node(tsp_final_solution, g->nodes[0], 0);
        add_node(tsp_final_solution, g->nodes[1], 2 * g->nodes[0]->cost[1]);
        return tsp_final_solution;
    }

    g->nodes[0]->colored = END;
    add_node(tsp_final_solution, g->nodes[0], 0);
    tsp_final_solution = brute_force(tsp_final_solution, g->nodes[0], g->count_nodes, 0);

    g->nodes[0]->colored = VISITED_BRUTE_FORCE;

    return tsp_final_solution;
}

Solution brute_force(Solution s, Node n, int total_node, int last_cost) {

    int i = 0, ref = 0, dim_tab = 0;
    Solution sub_solution = NULL;
    Solution* tab_solution = NULL;

    if ( (n->colored == END) && (s->count_nodes_s > 1)) {
        if((s->count_nodes_s < total_node)) {
            free_solution(s);
            return NULL;
        }
        add_node(s, n, last_cost);
        return s;
    }

    if ( n->colored == VISITED_BRUTE_FORCE) {
        free_solution(s);
        return NULL;
    }

    if (n->colored == UNVISITED) {
        n->colored = VISITED_BRUTE_FORCE;
        add_node(s, n, last_cost);
    }

    while(i < n->count_subnodes) {
        if ( n->subnodes[i] != NULL ) {
            sub_solution = copy_solution(s);
            sub_solution = brute_force(sub_solution, n->subnodes[i], total_node, n->cost[i]);

            if(sub_solution != NULL) {

                tab_solution = (Solution*) realloc(tab_solution, (dim_tab + 1) * sizeof(Solution));
                if ( tab_solution == NULL) {
                    free(tab_solution); /** Penser a free toutes les solution de tabsolution */
                    QUIT_MSG("Can't allocate more memory for tab_solution\n");
                }

                tab_solution[dim_tab] = sub_solution;
                ++dim_tab;
            }
        }
        ++i;
        
    }

    if(n->colored == VISITED_BRUTE_FORCE) {
        n->colored = UNVISITED;    
    }
    free_solution(s);
    ref = best_solution_id(tab_solution,dim_tab);
    if ( ref == -1 ) {
        return NULL;
    }

    for ( i = 0; i < dim_tab; i++ ) {
        if ( ref != i ) {
            free_solution(tab_solution[i]);
        }
    }
    s = tab_solution[ref];

    free(tab_solution);

    return s;
}


