//----------------------------------------------------------
// AUTEUR : LAOUSSING Kévin                                 |
// FICHIER : solution.c                                        |
// DATE : 27/10/14                                          |
//                                                          |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "solution.h"
#include "error.h"
#include "string.h"

Solution new_solution(int number_of_node) {

	Solution tsp_solution = NULL;

	tsp_solution = (Solution) calloc(1, sizeof(*tsp_solution));

	if ( tsp_solution == NULL ) {
        DEBUG_PRINTF("Empty Solution");
        QUIT_MSG("Can't allocate memory for a solution");
    }

    tsp_solution->list_node = (char*) calloc(2*number_of_node+1,sizeof(char));
    
    if ( tsp_solution->list_node == NULL ) {
        free(tsp_solution);
        DEBUG_PRINTF("Empty array of node");
        QUIT_MSG("Can't allocate memory for array of node");
    }

	return tsp_solution;
}

void add_node(Solution s, Node n, int cost)
{
	int i = 0;
	char* buff = malloc(5 * sizeof(char)); // buff peut stocker un nombre de l'ordre 10⁴;
	sprintf(buff, "%d", n->name);

	while(buff[i]!='\0') {
		i++;
	}
	
	strncat(s->list_node,buff,i);
	strcat(s->list_node,"\n");

	s->cost =+ cost;
	printf("%s\n",s->list_node );
	free(buff);
}

void free_solution(Solution s) {
	
	free(s->list_node);
	free(s);
}

void print_solution(const Solution s) {

	printf(	"Solution :\n\tlist_vertex : %s\n\tcost : %d\n", s->list_node, s->cost);
}
