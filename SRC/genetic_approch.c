#define MUTATION_RATE 0.5
#define CLONE_RATE 10
#define EPSILON 0.02

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

	return child;
}

void evolution() {
	return;
}

void genetic_approch(Graph g) {
	int i;
	Solution best = NULL;
	Solution *genetic = NULL;
	genetic = (Solution) calloc( NUMBER_SOLUTION, sizeof(Solution) );

	for ( i = 0; i < NUMBER_SOLUTION; i++ ) {
		genetic_approch[i] = random_approch(g, VISITED_RAND + (i + 1));
	}
	
	for ( i = 0; i < EVOLUTION_ITERATIONS; i++ ) {
		evolution(genetic);
	}
	

	best = best_solution(genetic, NUMBER_SOLUTION);
	print_solution(best);

	free_solution(best);

}
