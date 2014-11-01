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
    //tsp_solution->list_node = NULL;
   

	return tsp_solution;
}

void add_node(Solution s, Node n, int cost)
{	
	int len_buff = 0;
	char* buff = malloc(5 * sizeof(char));// buff peut stocker un nombre de l'ordre 10⁴;

	if (buff == NULL){
		fprintf(stderr, "ERROR can't allocate more memory !\n");
		free_solution(s);
		exit(EXIT_FAILURE);
	}
	sprintf(buff, "%d", n->name);
	strcat(buff,"\0");
	len_buff=strlen(buff) +1;


	if(s->list_node != NULL) {
		len_buff += strlen(s->list_node);

		s->list_node = (char*)realloc(s->list_node,len_buff*sizeof(char));
		if(s->list_node == NULL) {
			fprintf(stderr, "ERROR can't allocate more memory !\n");
			free_solution(s);
			exit(EXIT_FAILURE);
		}
		strncat(s->list_node,buff,len_buff);
	} else {
		s->list_node = (char*)calloc(len_buff,sizeof(char));
		if(s->list_node == NULL) {
			fprintf(stderr, "ERROR can't allocate more memory !\n");
			free_solution(s);
			exit(EXIT_FAILURE);
		}

		strcpy(s->list_node,buff);
	}
	/*while(buff[len_buff]!='\0') {
		len_buff++;
	}*/

	
	

	strcat(s->list_node," ");
	s->cost += cost;
	s->number_node_in_solution++;
	free(buff);
}

void copy_solution( Solution dest_s, Solution src_s) {
	
	dest_s->list_node = (char*)realloc(dest_s->list_node, (strlen(src_s->list_node)+1) * sizeof(char));
	
	if ( dest_s->list_node == NULL) {
		fprintf(stderr, "ERROR can't allocate more memory !\n");
		free_solution(dest_s);
		exit(EXIT_FAILURE);
	}

	strcpy(dest_s->list_node, src_s->list_node);
	dest_s->cost = src_s->cost;
	dest_s->number_node_in_solution = src_s->number_node_in_solution;
	dest_s->time = src_s->time;

}

Solution best_solution( Solution* list_solution, int nb_solution) {
	int i = 0;
	Solution best_solution = NULL;
	printf("|solution| %d\n", nb_solution );

	if (nb_solution == 0) {
		return NULL;
	}

	if ( nb_solution == 1) { puts("0000000000000");print_solution(list_solution[0]);
		return list_solution[0];
	}

	for ( i=0; (i+1)<nb_solution; i++) {

		print_solution(list_solution[i]);
		if (list_solution[i]->cost <= list_solution[i+1]->cost) {
			best_solution = list_solution[i];//print_solution(list_solution[i]);
			//free_solution(list_solution[i+1]);
		} else {
			best_solution = list_solution[i+1];
			//free_solution(list_solution[i]);
		}
	
	}
	return best_solution;
}

void free_solution(Solution s) {
	
	free(s->list_node);
	free(s);
	s=NULL;
}

void print_solution(const Solution s) {

	printf(	"Solution :\n\tlist_vertex : %s\n\tcost : %d\n\tNoNiS : %d\n", s->list_node, s->cost, s->number_node_in_solution);
}
