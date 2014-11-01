//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : tsp_brute_force.c                              |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "error.h"
#include "tsp_brute_force.h"
#include "graph.h"
#include "solution.h"
#include "node.h"


Solution tsp_brute_force(Graph g) {

	Solution tsp_final_solution = NULL;
	Solution tsp_final_solution2 = NULL;

	if ( g == NULL) {
		return tsp_final_solution;
	}

	tsp_final_solution = new_solution();

	if ( g->count_nodes == 1) {
		add_node(tsp_final_solution, g->nodes[0], 0);
		print_solution(tsp_final_solution);
		return tsp_final_solution;
	}

	if ( g->count_nodes == 2) {
		add_node(tsp_final_solution, g->nodes[0], 0);
		add_node(tsp_final_solution, g->nodes[1], 2 * g->nodes[0]->cost[0]);
		return tsp_final_solution;
	}

	g->nodes[1]->colored = END;
	add_node(tsp_final_solution,g->nodes[1],0);
	tsp_final_solution2 = brute_force(tsp_final_solution, g->nodes[1], g->count_nodes, 0);
	puts("coucou10");print_solution(tsp_final_solution);
	return tsp_final_solution2;
}

Solution brute_force(Solution s, Node n, int total_node, int last_cost) {

	int i = 0;
	int dim_tab = 0;
	Solution sub_solution=NULL;

	Solution* tab_solution = NULL;
	puts("entree brute_force");
	printf(">noeud courant %d\n",n->name);

	/*printf("noeud courant -> name %d || -> colour %d\n",n->name,n->colored);
	printf("solution nb noeud %d || total %d\n",s->number_node_in_solution,total_node);
	printf("nb sous noeuds %d\n", n->count_subnodes);*/
	if ( (n->colored == END) && (s->number_node_in_solution > 1)) {
		if((s->number_node_in_solution < total_node)) {
			free_solution(s);
			return NULL;
		}
		printf("Oh conno j'ai fais un cycle\n");
		add_node( s, n, last_cost);
		return s;
	}

	if ( n->colored == VISITED) {
		free_solution(s);
		puts("Visited");
		return NULL;
	}

	if (n->colored == UNVISITED) {
		n->colored = VISITED;
		add_node(s, n, last_cost);
	}

	while(i < n->count_subnodes) {
		sub_solution = new_solution();
		copy_solution(sub_solution, s);
		printf("In while subnode %d name : %d Origine : %d\n", i, n->subnodes[i]->name, n->name);
		sub_solution = brute_force(sub_solution, n->subnodes[i], total_node, n->cost[i]);

		if(sub_solution != NULL) {
			printf("sub_solution not null\n");
			tab_solution = (Solution*)realloc(tab_solution, (dim_tab + 1)*sizeof(Solution));
			if ( tab_solution == NULL) {
				free(tab_solution); /** Penser a free toutes les solution de tabsolution */
				QUIT_MSG("Can't allocate more memory for tab_solution\n");
			}

			tab_solution[dim_tab] = new_solution ();
			print_solution(sub_solution);
			copy_solution(tab_solution[dim_tab],sub_solution);
			++dim_tab;
			free_solution(sub_solution);
		}
		++i;
	}

	if(n->colored == VISITED) {
		n->colored = UNVISITED;	
	}
	free_solution(s);

	s = best_solution(tab_solution,dim_tab);


	return s;
}


