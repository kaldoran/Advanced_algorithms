//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : solution.c                                     |
// DATE : 27/10/14                                          |
//                                                          |
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

    tsp_solution->list_node = (Node*) calloc(count_nodes, sizeof(*tsp_solution->list_node));
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
	/* On copie le chemin précédent et on ajoute une place pour le noeud suivant */
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

	if (nb_solution == 0) {
		return -1;
	}

	if ( nb_solution == 1) { 
		return 0;
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
		/* On free pas les nodes car ils s'agit des pointeurs sur les nodes présent dans la structure graph*/
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

void cost_solution(const Solution s) {
	int i = 0;
	s->cost = 0;
	for ( i = 0; ( i + 1 ) < s->count_nodes_s; i++) {
		s->cost += s->list_node[i]->cost[s->list_node[i+1]->name];
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

