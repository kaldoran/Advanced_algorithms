//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin, REYNAUD Nicolas                |
// FICHIER : main.c                                         |
// DATE : 25/10/14                                          |
//----------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For fork and kill
#include <time.h>
#include <sys/time.h>
#include <signal.h>

#include "string.h"
#include "graph.h"
#include "node.h"
#include "solution.h"
#include "readfile.h"
#include "struct_graph.h"
#include "random_approach.h"
#include "greedy_approach.h"
#include "genetic_approach.h"
#include "brute_force_approach.h"
#include "branch_and_bound.h"
#include "branch_and_bound_rem.h"
#include "imnotaneasteregg.h"
#include "mst_approach.h"

#define NANOS 1000000

void print_time_taken( struct timespec start, struct timespec end) {
    struct timespec tmp;

    if ( (end.tv_nsec-start.tv_nsec) < 0 ) {
            tmp.tv_sec = end.tv_sec-start.tv_sec-1;
            tmp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    }
    else {
            tmp.tv_sec = end.tv_sec-start.tv_sec;
            tmp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }

    printf("\nTime nano : %ld nanosecondes\n", tmp.tv_nsec);
    printf("Time : %ld secondes %ld millisecondes %ld microsecondes %ld nanosecondes\n\n", tmp.tv_sec, tmp.tv_nsec / NANOS, (tmp.tv_nsec / 1000) % 1000, tmp.tv_nsec % 1000 );
    
}

int main(int argc, char const *argv[]) {
    (void)(argc);
    (void)(argv);
    pid_t aplay = NULL;
    struct timespec begin, end;


    Solution s = NULL;;
    Graph tsp_graph = NULL;
    srand(time(NULL));
    aplay = spawn_aplay("sound.wav");
 

if ( argc == 2 ) {
        tsp_graph = load(argv[1]);
        
        print_graph(tsp_graph);
        printf("Start Minimal Spanning Tree : \n");
        clock_gettime( CLOCK_REALTIME, &begin );
        s = MST(tsp_graph);
        clock_gettime( CLOCK_REALTIME, &end );
        print_solution(s);
        free_solution_bis(s);

        print_time_taken(begin, end);

        if ( tsp_graph->count_nodes <= 10 ) {
            printf("Start Brute Force : \n");
            clock_gettime( CLOCK_MONOTONIC, &begin );
            s = brute_force_approach(tsp_graph);
            clock_gettime(CLOCK_MONOTONIC, &end );
               print_solution(s);
            free_solution(s);

            print_time_taken(begin, end);
        }

        printf("Start Random Approach : \n");

        clock_gettime( CLOCK_REALTIME, &begin );
        s = random_approach(tsp_graph);
        clock_gettime( CLOCK_REALTIME, &end );
        print_solution(s);
        free_solution(s);

        print_time_taken(begin, end);

        printf("Start Greedy approach : \n");
        clock_gettime( CLOCK_REALTIME, &begin );
        s = greedy_approach(tsp_graph);
        clock_gettime( CLOCK_REALTIME, &end );
        print_solution(s);
        free_solution(s);

        print_time_taken(begin, end);

        
        if ( tsp_graph->count_nodes < 20 ) {
        	reset_coloration(tsp_graph);
	        printf("Start Branch and Bound approach: \n");
	        clock_gettime( CLOCK_REALTIME, &begin );
	        s = branch_and_bound(tsp_graph);
	        clock_gettime( CLOCK_REALTIME, &end );
	        print_solution(s);
	        free_solution(s);

	        print_time_taken(begin, end);
	    }
        
        
     
        reset_coloration(tsp_graph);
        printf("Start Genetic approach : \n");
        clock_gettime( CLOCK_REALTIME, &begin );
        s = genetic_approch(tsp_graph);
        clock_gettime( CLOCK_REALTIME, &end );
        print_solution(s);
        free_solution(s);

        print_time_taken(begin, end);

        free_graph(tsp_graph);

        kill(aplay, SIGTERM);
        exit(EXIT_SUCCESS);
    }
    
    exit(EXIT_SUCCESS);
}
