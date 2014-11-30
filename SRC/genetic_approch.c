//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : error.h                                        |
// DATE : 27/10/14                                          |
//                                                          |
// - Debug Maccro [C99 Convention]                          |
// - Quit maccro                                            |
//----------------------------------------------------------

#define MUTATION_RATE 20
#define CLONE_RATE 1

#define ELITE_PARENT 		 10 
#define ELITE_POURCENT		 10
#define TOURNAMENT_POURCENT  10
#define NUMBER_SOLUTION 	 50
#define EVOLUTION_ITERATIONS 100

#define TOURNAMENT_SIZE     (( NUMBER_SOLUTION * TOURNAMENT_POURCENT) / 100)
#define TOTAL_ELITE 		(( NUMBER_SOLUTION * ELITE_POURCENT) / 100)

#define RANDOM(MIN, MAX)	((rand() % ( MAX - MIN )) + MIN )
#define UNUSED(X) (void)(X)

#include <limits.h>

#include "struct_graph.h"
#include "solution.h"
#include "error.h"
#include "random_approch.h"

Solution mutate(Solution s) {
	int max_value = s->count_nodes_s - 1;
	int swap =   rand() % max_value; /* Can't swap start and end node */
	int toswap = rand() % max_value;
	if ( swap == max_value || toswap == max_value )  { s->list_node[0] = s->list_node[((swap == max_value) ? toswap : swap) ]; }
	if ( swap == 0 || toswap == 0 )  				 { s->list_node[max_value] = s->list_node[((swap == 0) ? toswap : swap) ]; }

	Node save = NULL;

	save = s->list_node[swap];
	s->list_node[swap] = s->list_node[toswap];
	s->list_node[toswap] = save;	
	return s;
}

Solution crossover(const Solution s1, const Solution s2) {

	Solution child = NULL;
	int i, start, end, rdm_index1, rdm_index2;

	if ( rand() % 100 < CLONE_RATE ) {
		if ( s1->cost < s2->cost) {
			return copy_solution(s1);
		}
		
		return copy_solution(s2);
	}
	
	rdm_index1 = rand() % (s1->count_nodes_s - 1);
	rdm_index2 = rand() % (s1->count_nodes_s - 1);
		
	if ( rdm_index1 == rdm_index2 ) {
		return copy_solution(s2);
	}

	child = new_solution(s1->count_nodes_s);

	start = (rdm_index1 <= rdm_index2 ) ? rdm_index1 : rdm_index2;
	end   = (rdm_index1 > rdm_index2 ) ? rdm_index1 : rdm_index2;

	for ( i = start; i < end; i++ ) {
		add_node(child, s1->list_node[i], 0);
	}
		
	for ( i = 0; i < s2->count_nodes_s - 1; i++ ) {
		if( !contains(child, s2->list_node[i]) ) {
			add_node(child, s2->list_node[i], 0);
		}
	}
	add_node(child, child->list_node[0], 0);
	return child;
}

Solution tournment(Solution *sorted) {

	if ( rand() % 100 < ELITE_PARENT) {
		return sorted[rand() % TOTAL_ELITE];
	}

	int i;
	Solution best = NULL;
	Solution *tournment = (Solution*) calloc( TOURNAMENT_SIZE, sizeof(Solution));
	
	if ( tournment == NULL ) {
		QUIT_MSG("Can't allocate memory for tournement");
	}

	for ( i = 0; i < TOURNAMENT_SIZE; i++ ) {
		tournment[i] = sorted[rand() % (NUMBER_SOLUTION - 1) ];
	}
	i = best_solution_id(tournment, TOURNAMENT_SIZE );

	best = tournment[i];
	free(tournment);

	return best;
}

Solution *evolution(const Graph g, Solution *genetic) {

	int i = 0, j = 0, k = 0, bestCost, node_left, bestNode = 0;
	
	Solution *sorted = (Solution*) calloc( NUMBER_SOLUTION, sizeof(Solution) );
	node_left = NUMBER_SOLUTION;	

	if ( sorted == NULL ) {
		QUIT_MSG("Can't allocate memory for sorted");
	}

	/* Tri */
	for( i = 0; i < NUMBER_SOLUTION; i++ ) {
		bestCost = INT_MAX;
		for( j = 0; j < NUMBER_SOLUTION; j++ ) {
			if ( genetic[i] != NULL ) {
				if ( genetic[i]->cost <= bestCost ) {
					bestNode = i;
					bestCost = genetic[i]->cost;
				}
			}
		}
		sorted[k] = copy_solution(genetic[bestNode]); /* Deplacement du pointeur */
		free_solution(genetic[bestNode]);
		++k;
	}

	node_left -= TOTAL_ELITE;
		
	for ( i = 0; i < TOTAL_ELITE; i++ ) {
		if ( rand() % 100 < MUTATION_RATE ) {
			genetic[i] = copy_solution(mutate(sorted[i]));
			cost_solution(g, genetic[i]);
		}
		else {
			genetic[i] = copy_solution(sorted[i]);
		}
	}

	while( node_left > 0 ) {
		Solution p1 = tournment(sorted);
		Solution p2 = tournment(sorted);

		Solution child = crossover(p1, p2);
		
		if ( rand() % 100 < MUTATION_RATE ) {
			genetic[i] = mutate(child);
		} else { 
			genetic[i] = child;
		}

		cost_solution(g, genetic[i]);
		
		++i;
		--node_left;
	}

	for ( i = 0; i < NUMBER_SOLUTION; i++ ) {
		free_solution(sorted[i]);
	}

//	free(genetic);
	free(sorted);
	return genetic;
}

Solution genetic_approch(Graph g) {
	int i = 0;
	int ref = 0;

	Solution best = NULL;
	Solution *genetic = (Solution*) calloc( NUMBER_SOLUTION, sizeof(Solution) );
	if ( genetic == NULL ) {
		QUIT_MSG("Can't allocated Solution");
	}

	printf("Starting generate population");
	for ( i = 0; i < NUMBER_SOLUTION; i++ ) {
		genetic[i] = random_approch_compute(g, VISITED_RAND + (i + 1));
	}
	
	printf("Starting Evolution");
	for ( i = 0; i < EVOLUTION_ITERATIONS; i++ ) {
		genetic = evolution(g, genetic);
	}

	ref = best_solution_id(genetic, NUMBER_SOLUTION);
	for ( i = 0; i < NUMBER_SOLUTION; i++) {
		if ( i != ref ) {
			free_solution(genetic[i]);
		}
	}

	best = genetic[ref];
	free(genetic);

	
	return best;
}
