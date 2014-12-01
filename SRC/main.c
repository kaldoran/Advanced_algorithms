//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : main.c                                         |
// DATE : 25/10/14                                          |
//----------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /** For fork and kill */
#include <time.h>
#include <sys/time.h>
#include <signal.h>

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

#include "imnotaneasteregg.h"

#include "tsp_mst.h"

/** Temporary maccro */
#define UNUSED(x) (void)(x)

int main(int argc, char const *argv[]) {
    UNUSED(argc);
    UNUSED(argv);
    pid_t aplay = NULL;
    struct timeval tv1,tv2;

    Solution s=NULL;;
    Graph tsp_graph = NULL;
    srand(time(NULL));
	aplay = spawn_aplay("sound.wav");
 

if ( argc == 2 ) {
        tsp_graph = load(argv[1]);
        
        print_graph(tsp_graph);
        printf("Start Minimal Spanning Tree : \n");
        gettimeofday(&tv1,NULL);
        s = MST(tsp_graph);
        gettimeofday(&tv2,NULL);
        print_solution(s);
        free_solution_bis(s);
           
        printf("temps = %lld microsecondes\n\n", (long long) (tv2.tv_usec - tv1.tv_usec) );

        printf("Start Brute Force : \n");
        gettimeofday(&tv1,NULL);
        s = tsp_brute_force(tsp_graph);
        gettimeofday(&tv2,NULL);
        print_solution(s);
        free_solution(s);
           
        printf("temps = %lld microsecondes\n\n", (long long) (tv2.tv_usec - tv1.tv_usec) );
          
        printf("Start Random Approch : \n");

        gettimeofday(&tv1,NULL);
		/* Pemettra de faire plusieurs graphs random, sans avoir a réset la coloration entre chaque boucle */

        s = random_approch(tsp_graph);
        gettimeofday(&tv2,NULL);
        print_solution(s);
        free_solution(s);
           
        printf("temps = %lld microsecondes\n\n", (long long) (tv2.tv_usec - tv1.tv_usec) );

        printf("Start Greedy approch : \n");
        gettimeofday(&tv1,NULL);
        s = greedy_approch(tsp_graph);
        gettimeofday(&tv2,NULL);
        print_solution(s);
        free_solution(s);

        printf("temps = %lld microsecondes\n\n", (long long) (tv2.tv_usec - tv1.tv_usec) );

        reset_coloration(tsp_graph);
        printf("Start Branch and Bound approch: \n");
        gettimeofday(&tv1,NULL);
        s = branch_and_bound(tsp_graph);
        gettimeofday(&tv2,NULL);
        print_solution(s);
        free_solution(s);
           
        printf("temps = %lld microsecondes\n\n", (long long) (tv2.tv_usec - tv1.tv_usec) );

//        !!!! ATTENTION NE MARCHE PAS !!!! (c'est pas la peine de venir critiquer si décommenté !)
/*        printf("Start Branch and Bound approch (removing edges version) : \n");
        gettimeofday(&tv1,NULL);
        s = branch_and_bound_rem(tsp_graph);
        gettimeofday(&tv2,NULL);
        print_solution(s);
        free_solution(s);
        
        printf("temps = %lld microsecondes\n\n", (long long) (tv2.tv_usec - tv1.tv_usec) );
*/      
        reset_coloration(tsp_graph);
        printf("Start Genetic approch : \n");
        gettimeofday(&tv1,NULL);
        s = genetic_approch(tsp_graph);
        gettimeofday(&tv2,NULL);
        print_solution(s);
        free_solution(s);

        printf("temps = %lld microsecondes\n\n", (long long) (tv2.tv_usec - tv1.tv_usec) );
        free_graph(tsp_graph);

		kill(aplay, SIGTERM);
        exit(EXIT_SUCCESS);
    }
    
    exit(EXIT_SUCCESS);
}
