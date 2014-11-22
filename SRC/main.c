//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : main.h                                         |
// DATE : 25/10/14                                          |
//----------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "string.h"
#include "graph.h"
#include "node.h"
#include "solution.h"
#include "readfile.h"
#include "struct_graph.h"
#include "random_approch.h"
#include "greedy_approch.h"
#include "tsp_brute_force.h"
#include "branch_and_bound.h"


/** Temporary maccro */
#define UNUSED(x) (void)(x)

int main(int argc, char const *argv[]) {
	UNUSED(argc);
    UNUSED(argv);
	
	clock_t start;

    Graph tsp_graph = NULL;

if ( argc == 2 ) {
		tsp_graph = load(argv[1]);
		print_graph(tsp_graph);
		
		start = clock();
		free_solution(tsp_brute_force(tsp_graph));

		printf("\n\t\t Time taken %f seconds", (double) ((clock() - start) / CLOCKS_PER_SEC) );
				
		start = clock();
		/* Pemettra de faire plusieurs graphs random, sans avoir a réset la coloration entre chaque boucle */
		free_solution(random_approch(tsp_graph, VISITED_RAND));

		printf("\n\t\t Time taken %f seconds", (double) ((clock() - start) / CLOCKS_PER_SEC) );
		
		start = clock();
		greedy_approch(tsp_graph);
		printf("\n\t\t Time taken %f seconds", (double) ((clock() - start) / CLOCKS_PER_SEC) );
		
		start = clock();
		branch_and_bound(tsp_graph);
		printf("\n\t\t Time taken %f seconds", (double) ((clock() - start) / CLOCKS_PER_SEC) );
		
		
		free_graph(tsp_graph);
		exit(EXIT_SUCCESS);
	}
	
	exit(EXIT_SUCCESS);
}
