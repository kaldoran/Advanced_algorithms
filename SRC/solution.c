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

    tsp_solution->list_node= NULL;

	return tsp_solution;
}

void add_node(Solution s, Node n, int cost)
{
  	int len1 = 1/*strlen(n->name)*/, len2 = strlen(s->list_node);
	char *buf;
 
	if((buf = malloc((len1 + len2 + 2) * sizeof *buf)) == NULL) {
		QUIT_MSG("Can't allocate memory for new buffer");
	}
 
	sprintf(buf, "%d", n->name);
	strcpy(buf + len1, s->list_node);
	strcpy(buf + len1 + len2, "\n");
 
	s->list_node = buf;
	s->cost += cost;
 }

void free_solution(Solution s) {
	
	free(s->list_node);
	free(s);
}

void print_solution(const Solution s) {

	printf(	"Solution :\n\tlist_vertex : %s\n\tcost : %d\n", s->list_node, s->cost);
}
