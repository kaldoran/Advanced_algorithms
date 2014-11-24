#define MUTATION_RATE 50
#define CLONE_RATE 10
#define EPSILON 0.02

#define ELITE_PARENT 		 10 
#define ELITE 				 10
#define NUMBER_SOLUTION 	 100
#define EVOLUTION_ITERATIONS 100

#include "struct_graph.h"
#include "solution.h"

void mutate(Solution s) {
	int swap = rand() % s->count_nodes_s;
	int toswap = rand() % s->count_nodes_s;

	Node save = NULL;
	save = s->list_node[toswap]; 
	s->list_node[swap] = s->list_node[toswap];
	s->list_node[toswap] = save;	
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
	cost_solution(child);
	return child;
}

int contains(Solution s, Node n ) {
	int i;
	
	for ( i = 0; ; i < s->count_nodes_s; i++ ) {
		if ( s->list_node[i] = n ) {
			return 1;
		}
	}

	return 0;
}

void evolution(Solution *genetic) {
	int i = 0, j = 0, index = 0, bestIndex, bestCost;
	Solution *sorted = (Solution*) calloc( NUMBER_SOLUTION, sizeof(Solution) );
	
	if ( sorted == NULL ) {
		QUIT_MSG("Can't allocate sorted");
	}

	/* Tri */
	for( i = 0; i < NUMBER_SOLUTION; i++ ) {
		bestCost = MAX_INT;
		bestIndex = 0;
		for( j = 0; j < NUMBER_SOLUTION; j++ ) {
			if (genetic[i] != NULL ) {
				if ( genetic[i]->cost < bestCost ) {
					bestCost = genetic[i]->cost;
					sorted[j] = genetic[i]; /* Deplacement du pointeur */
					genetic[i] = NULL;
					++j;
				}	
			}	
		}
	}
	
	free(genetic);
	for ( i = 0; i < ELITE; i++ ) {
		if ( rand() % 100 < MUTATION_RATE ) {
			sorted[i] = mutate(sorted[i]);
			cost_solution(sorted[i]);
		}	
	}

	while( ) {
		Solution p1 = tournment(sorted);
		Solution p2 = tournment(sorted);
		
		Solution child = new_solution(p1->count_nodes_s);

	}
	
	return sorted;
}

void genetic_approch(Graph g) {
	int i;
	Solution best = NULL;
	Solution *genetic = NULL;
	genetic = (Solution*) calloc( NUMBER_SOLUTION, sizeof(Solution) );
	if ( genetic == NULL ) {
		QUIT_MSG("Can't allocated Solution");
	}

	for ( i = 0; i < NUMBER_SOLUTION; i++ ) {
		genetic[i] = random_approch(g, VISITED_RAND + (i + 1));
	}
	
	for ( i = 0; i < EVOLUTION_ITERATIONS; i++ ) {
		evolution(genetic);
	}
	

	best = best_solution(genetic, NUMBER_SOLUTION);
	print_solution(best);

	free_solution(best);

}
