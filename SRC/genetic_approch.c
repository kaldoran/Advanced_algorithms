#define MUTATION_RATE 50
#define CLONE_RATE 10

#define ELITE_PARENT 		 10 
#define ELITE_POURCENT		 10
#define TOURNAMENT_POURCENT  10
#define NUMBER_SOLUTION 	 50
#define EVOLUTION_ITERATIONS 1

#define TOURNAMENT_SIZE     (( NUMBER_SOLUTION * TOURNAMENT_POURCENT) / 100)
#define TOTAL_ELITE 		(( NUMBER_SOLUTION * ELITE_POURCENT) / 100)

#define UNUSED(X) (void)(X)

#include <limits.h>

#include "struct_graph.h"
#include "solution.h"
#include "error.h"
#include "random_approch.h"

Solution mutate(Solution s) {

	int swap = rand() % (s->count_nodes_s - 1) + 1; /* 2 Time starting node*/
	int toswap = rand() % (s->count_nodes_s - 1) + 1;
	//DEBUG_PRINTF("%d - %d", swap, toswap);
	Node save = NULL;

	save = s->list_node[toswap]; 
	s->list_node[swap] = s->list_node[toswap];
	s->list_node[toswap] = save;	

	return s;
}

int contains(Solution s, Node n ) {
	int i;
	
	for ( i = 0; i < s->count_nodes_s; i++ ) {
		if ( s->list_node[i] == n ) {
			return 1;
		}
	}

	return 0;
}

Solution crossover(const Solution s1, const Solution s2) {

	if ( rand() % 100 < CLONE_RATE ) {
		if ( s1->cost < s2->cost) {
			return s1;
		}
		else {
			return s2;
		}
	}
	
	Solution child = new_solution(s1->count_nodes_s);
	int i, start, end, rdm_index1, rdm_index2;

	rdm_index1 = rand() % s1->count_nodes_s;
	rdm_index2 = rand() % s2->count_nodes_s;
	
	start = (rdm_index1 <= rdm_index2 ) ? rdm_index1 : rdm_index2;
	end   = (rdm_index1 > rdm_index2 ) ? rdm_index2 : rdm_index1;

	for ( i = start; i < end; i++ ) {
		add_node(child, s1->list_node[i], 0);
	}

	for ( i = 0; i < s2->count_nodes_s; i++ ) {
		if( !contains(child, s2->list_node[i]) ) {
			add_node(child, s2->list_node[i], 0);
		}
	}

	return child; /* Cost on return child */
}

Solution tournment(Solution *sorted) {

	if ( rand() % 100 < ELITE_PARENT) {
		return sorted[0];
		//return sorted[rand() % TOTAL_ELITE];
	}

	int i;
	Solution *tournment = (Solution*) calloc( TOURNAMENT_SIZE, sizeof(Solution));
	
	for ( i = 0; i < TOURNAMENT_SIZE; i++ ) {
		tournment[i] = sorted[rand() % (NUMBER_SOLUTION - 1) ];
	}
	free(tournment);
	return sorted[0];
	//return best_solution(tournment, TOURNAMENT_SIZE);
}

void evolution(Solution *genetic) {

	int i = 0, j = 0, k = 0, bestCost, node_left, bestNode = 0;
	Solution *sorted = (Solution*) calloc( NUMBER_SOLUTION, sizeof(Solution) );
	node_left = NUMBER_SOLUTION;	
	if ( sorted == NULL ) {
		QUIT_MSG("Can't allocate sorted");
	}

	/* Tri */
	for( i = 0; i < NUMBER_SOLUTION; i++ ) {
		bestCost = INT_MAX;

		for( j = 0; j < NUMBER_SOLUTION; j++ ) {
			if (genetic[i] != NULL ) {
				if ( genetic[i]->cost <= bestCost ) {
					bestNode = i;
					bestCost = genetic[i]->cost;
				}	
			}	
		}
		
		sorted[k] = genetic[bestNode]; /* Deplacement du pointeur */
		//fprintf(stderr, "Sorted : %p - Genetic %p\n", sorted[k], genetic[bestNode]);
		genetic[i] = NULL;

		++k;
	}

	node_left -= TOTAL_ELITE;
	
	for ( i = 0; i < TOTAL_ELITE; i++ ) {
		if ( rand() % 100 < MUTATION_RATE ) {
			genetic[i] = mutate(sorted[i]);
			cost_solution(genetic[i]);
		}	
	}

	DEBUG_PRINTF("END MUTATION - %d ",  node_left);
	while( node_left >= 0 ) {
		Solution p1 = tournment(sorted);
		Solution p2 = tournment(sorted);

		fprintf(stderr, "%p - %p - node left : %d i : %d\n", p1, p2, node_left, i);
		Solution child = crossover(p1, p2);
		if ( rand() % 100 < MUTATION_RATE ) {
			genetic[i] = mutate(child);
			cost_solution(child);
		} else { 
			genetic[i] = child;
		}
		++i;
		--node_left;
	}

	free(sorted);
	return;
}

Solution genetic_approch(Graph g) {
	int i;
	Solution best = NULL;
	Solution *genetic = NULL;
	genetic = (Solution*) calloc( NUMBER_SOLUTION, sizeof(Solution) );
	if ( genetic == NULL ) {
		QUIT_MSG("Can't allocated Solution");
	}

	for ( i = 0; i < NUMBER_SOLUTION; i++ ) {
		genetic[i] = random_approch(g, VISITED_RAND + (i + 1));
		print_solution(genetic[i]);
	}

	DEBUG_PRINTF("END GENERATE");	
/*	for ( i = 0; i < EVOLUTION_ITERATIONS; i++ ) {
		evolution(genetic);
	}


	DEBUG_PRINTF("END EVOL");
	best = best_solution(genetic, NUMBER_SOLUTION);
	print_solution(best);

	*/
	free_solution(best);
	
	return best;
}
