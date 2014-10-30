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

Solution new_solution() {

	Solution tsp_solution = NULL;

	tsp_solution = (Solution) calloc(1, sizeof(*tsp_solution));

	if ( tsp_solution == NULL ) {
        DEBUG_PRINTF("Empty Solution");
        QUIT_MSG("Can't allocate memory for a solution");
    }

    tsp_solution->list_node = (char*) calloc(1,sizeof(char));
    
    if ( tsp_solution->list_node == NULL ) {
        free(tsp_solution);
        DEBUG_PRINTF("Empty array of node");
        QUIT_MSG("Can't allocate memory for array of node");
    }

	return tsp_solution;
}

void add_node(Solution s, Node n, int cost)
{
	int len_buff = 0;
	char* buff = malloc(5 * sizeof(char)); // buff peut stocker un nombre de l'ordre 10⁴;
	sprintf(buff, "%d", n->name);

	while(buff[len_buff]!='\0') {
		len_buff++;
	}

	s->list_node = (char*)realloc(s->list_node,len_buff*sizeof(char));
		
	strncat(s->list_node,buff,len_buff);
	strcat(s->list_node," ");

	s->cost += cost;
	free(buff);
}

void free_solution(Solution s) {
	
	free(s->list_node);
	free(s);
}

void print_solution(const Solution s) {

	printf(	"Solution :\n\tlist_vertex : %s\n\tcost : %d\n", s->list_node, s->cost);
}
