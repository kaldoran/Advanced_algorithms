//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : greedy_approch.c                               |
// DATE : 27/10/14                                          |
//                                                          |
// - Debug Maccro [C99 Convention]                          |
// - Quit maccro                                            |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "error.h"
#include "solution.h"
#include "graph.h"

Solution greedy_approch(Graph g) {
    Solution s;
    Node current;
    int i, choix, total_node, current_mini, start;

    s = new_solution(g->count_nodes); 
    choix = 0;
    total_node = 1; /* Starting node */
    current_mini = INT_MAX; 

    start = 0;
    current = g->nodes[start];
    current->colored = END;
    add_node(s, current, 0); /** Add starting node */

    do {
    
        current_mini = INT_MAX;

        for ( i = 0; i < current->count_subnodes; i++) {
            if ( current->subnodes[i] != NULL
              && current->subnodes[i]->colored != VISITED_GREEDY
              && current->subnodes[i]->colored != END
              && current->cost[i] < current_mini ) {
            
                    choix = i;
                    current_mini = current->cost[i];
            }
        }
    
        ++total_node; 
        
        current = current->subnodes[choix];
        add_node(s, current, current_mini);
        current->colored = VISITED_GREEDY;
        
    }while(g->count_nodes != total_node); /* Never append */
    g->nodes[start]->colored = VISITED_GREEDY;
    add_node(s, g->nodes[start], current->cost[start]); /** Add at the end */
    
    return s;
}

