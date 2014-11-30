//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : main.c                                         |
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
#include "branch_and_bound_rem.h"
#include "genetic_approch.h"

#include "tsp_mst.h"

/** Temporary maccro */
#define UNUSED(x) (void)(x)

int main(int argc, char const *argv[]) {
	UNUSED(argc);
    UNUSED(argv);
	
	clock_t start;
	Solution s=NULL;;
    Graph tsp_graph = NULL;
	srand(time(NULL));
    system("aplay -D sysdefault -c 1 -q -t wav sound.wav &");

if ( argc == 2 ) {
		tsp_graph = load(argv[1]);
		
		print_graph(tsp_graph);
/*		printf("Most sapnning tree : \n");
		start = clock();
		s = MST(tsp_graph);
		print_solution(s);
		free_solution_bis(s);
		printf("\n\t\t Time taken %f m-seconds\n\n", (double) (clock() - start));
		
		printf("Start Brute Force : \n");
		start = clock();
		s = tsp_brute_force(tsp_graph);
		print_solution(s);
		free_solution(s);
		printf("\n\t\t Time taken %f m-seconds\n\n", (double) (clock() - start));
*/				
		printf("Start Random Approch : \n");
		start = clock();
		/* Pemettra de faire plusieurs graphs random, sans avoir a réset la coloration entre chaque boucle */
		s = random_approch(tsp_graph);
		print_solution(s);
		free_solution(s);
		printf("\n\t\t Time taken %f m-seconds\n\n", (double) (clock() - start) );
/*		
		printf("Start Greedy approch : \n");
		start = clock();
		s = greedy_approch(tsp_graph);
		print_solution(s);
		free_solution(s);
		printf("\n\t\t Time taken %f m-seconds\n\n", (double) (clock() - start) );		

		printf("Start Branch and Bound approch: \n");
		start = clock();
		s = branch_and_bound(tsp_graph);
		print_solution(s);
		free_solution(s);
		printf("\n\t\t Time taken %f m-seconds\n\n", (double) (clock() - start) );

		!!!! ATTENTION PAS TESTE !!!! (c'est pas la peine de venir critiquer si décommenté !)
		printf("Start Branch and Bound approch (removing edges version) : \n");
		start = clock();
		s = branch_and_bound_rem(tsp_graph);
		print_solution(s);
		free_solution(s);
		printf("\n\t\t Time taken %f m-seconds\n\n", (double) (clock() - start) );
*/
		reset_coloration(tsp_graph);
		printf("Start Genetic approch : \n");
		start = clock();
		s = genetic_approch(tsp_graph);
		print_solution(s);
		free_solution(s);
		printf("\n\t\t Time taken %f m-seconds\n\n", (double) (clock() - start) );
		
	
		free_graph(tsp_graph);
		exit(EXIT_SUCCESS);
	}
	
	exit(EXIT_SUCCESS);
}
