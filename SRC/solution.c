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

void add_node(Solution s, Node n, int cost) {

	char tmp[20];
	sprintf(tmp, "%d", n->name);
	int size_string = strlen(s->list_node) + strlen(tmp) + 1;
	char buffer[size_string];

	strcpy(buffer, s->list_node);
	strcat(buffer, tmp);

	s->list_node = NULL;
	s->list_node = buffer;
	s->cost = s->cost + cost;
}

void free_solution(Solution s) {
	
	free(s->list_node);
	free(s);
}

void print_solution(const Solution s) {

	printf(	"Solution :\n\tlist_vertex : %s\n\tcost : %d\n", s->list_node, s->cost);
}