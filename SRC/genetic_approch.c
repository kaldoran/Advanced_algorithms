#define MUTATION_RATE 50
#define CLONE_RATE 10
#define EPSILON 0.02

#define ELITE_PARENT 		 10 
#define ELITE 				 10
#define NUMBER_SOLUTION 	 100
#define EVOLUTION_ITERATIONS 100

#define UNUSED(X) (void)(X)

#include <limits.h>

#include "struct_graph.h"
#include "solution.h"
#include "error.h"
#include "random_approch.h"

void mutate(Solution s) {
	print_solution(s);
	int swap = rand() % (s->count_nodes_s - 1) + 1; /* 2 Time starting node*/
	int toswap = rand() % (s->count_nodes_s - 1);
	DEBUG_PRINTF("%d - %d\n", swap, toswap);
	Node save = NULL;

	save = s->list_node[toswap]; 
	s->list_node[swap] = s->list_node[toswap];
	s->list_node[toswap] = save;	
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

	if ( rand() < CLONE_RATE ) {
		free_solution(child);
		if ( s1->cost < s2->cost) {
			return s1;
		}
		else {
			return s2;
		}
	}

	return child; /* Cost on return child */
}

Solution tournment(Solution *sorted) {
	return sorted[0]; 
}

void evolution(Solution *genetic) {
	int i = 0, j = 0, bestCost;
	Solution *sorted = (Solution*) calloc( NUMBER_SOLUTION, sizeof(Solution) );
	
	if ( sorted == NULL ) {
		QUIT_MSG("Can't allocate sorted");
	}

	/* Tri */
	for( i = 0; i < NUMBER_SOLUTION; i++ ) {
		bestCost = INT_MAX;

		for( j = 0; j < NUMBER_SOLUTION; j++ ) {
			if (genetic[i] != NULL ) {
				if ( genetic[i]->cost <= bestCost ) {
					bestCost = genetic[i]->cost;
					sorted[j] = genetic[i]; /* Deplacement du pointeur */
					genetic[i] = NULL;
				}	
			}	
		}
		++j;
		fprintf(stderr,"Pointeur de sorted : %p", sorted[j]);
	}
	
	//free(genetic);
	for ( i = 0; i < ELITE; i++ ) {
		print_solution(sorted[i]);
		if ( rand() % 100 < MUTATION_RATE ) {
			mutate(sorted[i]);
			cost_solution(sorted[i]);
		}	
	}

	while( 1 ) {
		Solution p1 = tournment(sorted);
		Solution p2 = tournment(sorted);
		
		UNUSED(p1);
		UNUSED(p2);
		Solution child = new_solution(p1->count_nodes_s);
		UNUSED(child);
	}
	
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
	for ( i = 0; i < EVOLUTION_ITERATIONS; i++ ) {
		evolution(genetic);
	}
	

	best = best_solution(genetic, NUMBER_SOLUTION);
	print_solution(best);

	free_solution(best);
	
	return best;
}
