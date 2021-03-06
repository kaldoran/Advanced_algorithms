//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : solution.c                                     |
// DATE : 05/11/14                                          |
//                                                          |
// - Implementation of the prototypes in solution.h         |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "solution.h"
#include "error.h"
#include "string.h"

Solution new_solution(const int count_nodes) {

    Solution tsp_solution = NULL;

    tsp_solution = (Solution) calloc(1, sizeof(*tsp_solution));

    if ( tsp_solution == NULL ) {
        DEBUG_PRINTF("Empty solution");
        QUIT_MSG("Can't allocate memory for a solution");
    }

    tsp_solution->list_node = (Node*) calloc(count_nodes + 1, sizeof(*tsp_solution->list_node));
       if ( tsp_solution->list_node == NULL ) {
        DEBUG_PRINTF("Empty Array Node Solution");
        QUIT_MSG("Can't allocate memory for array of solution");
    }

    return tsp_solution;
}

void add_node(Solution s, const Node n, const int cost) {
    s->list_node[s->count_nodes_s] = n;
    ++s->count_nodes_s;
    s->cost += cost;
    
}

Solution copy_solution( Solution src_s) {

    int i = 0;
    /* We copy the solution and add a place for the loop node */
    Solution dest_s = new_solution(src_s->count_nodes_s + 1 );

    for ( i = 0; i < src_s->count_nodes_s; i++) {
        dest_s->list_node[i] = src_s->list_node[i];
    }

    dest_s->cost = src_s->cost;
    dest_s->count_nodes_s = src_s->count_nodes_s;
    
    return dest_s;
}

int best_solution_id( Solution* list_solution, int nb_solution) {
    int i = 0;
    int ref = 0;
    int minCost = INT_MAX;
    
    if (nb_solution == 0 || nb_solution == 1) {
        return  nb_solution - 1;
    }
    
    for ( i=0; i < nb_solution; i++) {
        if (list_solution[i]->cost <= minCost) {
            ref = i;
            minCost = list_solution[i]->cost;
        }
    }

    return ref;
}

void free_solution(Solution s) {
    if ( s != NULL ) {
        /* We don't free the nodes of list_node because these nodes is the same as in the graph */
        free(s->list_node);
        free(s);
    }
}

void free_solution_bis(Solution s) {
    int i = 0;
    for(i = 0; i < s->count_nodes_s; i++) {
        free(s->list_node[i]->subnodes);
        free(s->list_node[i]->cost);
        free(s->list_node[i]);
    }
    free(s->list_node);
    free(s);
}

void print_solution(const Solution s) {
    int i = 0; 
    printf("Solution:\n\tList Vertex : ");
    for ( i = 0; i < s->count_nodes_s; i++ ) {
        printf("%d ", s->list_node[i]->name);
    }

    printf("\n\tCost : %d\n\tNode Count : %d\n", s->cost, s->count_nodes_s);
}

void cost_solution(const Graph g, const Solution s) {
    int i = 0;
    s->cost = 0;

    for(i = 0; i < s->count_nodes_s - 1 ; i++) {
        s->cost += g->nodes[s->list_node[i]->name]->cost[s->list_node[i+1]->name];
    }
}


int contains(Solution s, Node n ) {
    int i;
    
    for ( i = 0; i < s->count_nodes_s; i++ ) {
        if ( s->list_node[i] != NULL 
          && s->list_node[i]->name == n->name ) {
            return 1;
        }
    }

    return 0;
}

