//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_opti.c                             |
// DATE : 28/10/14                                          |
//----------------------------------------------------------

#include "branch_and_bound_opti.h"


Solution branch_and_bound_rec_opti(Solution part, Solution best, Graph tspGraph) {
	int cost = 0, k, j;
	if(part->count_nodes_s == best->count_nodes_s -1){
		printf("np = nb\n");
		k=0;
		while(part->list_node[0]->subnodes[k]->name != part->list_node[part->count_nodes_s-1]->name) {
			++k;
		}
		cost = part->cost + part->list_node[0]->cost[k];
		if(cost < best->cost) {
			best = copy_solution(part);
			add_node(best, part->list_node[0],part->list_node[0]->cost[k]);
		}
		printf("best:");print_solution(best);
	}
	else{
		for(j=0; j < tspGraph->count_nodes; ++j) {
			printf("1-j: %d, count_nodes_s %d, tsp[j]: %d, color %d\n",j,tspGraph->count_nodes,tspGraph->nodes[j]->name,tspGraph->nodes[j]->colored);
			int last = part->count_nodes_s-1;
			if( part->list_node[last]->subnodes[j] != NULL
			 && part->list_node[last]->subnodes[j]->colored == UNVISITED) {

				cost = part->cost + part->list_node[last]->cost[j];
				if(cost < best->cost) {
					add_node(part,part->list_node[last]->subnodes[j],part->list_node[last]->cost[j]);
					printf("2-j: %d, count_nodes_s %d, tsp[j]: %d\n",j,part->count_nodes_s,tspGraph->nodes[j]->name);
					printf("part:");print_solution(part);
					part->list_node[last]->subnodes[j]->colored = VISITED_BNB;
					best = branch_and_bound_rec_opti(part, best, tspGraph);
					part->list_node[last]->subnodes[j]->colored = UNVISITED;
				}
			}
		}
	}
	return best;
}

int branch_and_bound_opti(Graph tspGraph) {
	//Indice du noeud de départ.
	int start = 0; 

	int i = 0, j = 1;

	//Noeud pour parcourir le graphe et creer un premier chemin dans best.
	Node current = NULL; 

	//Chemin de la solution partielle.
	Solution part = new_solution(tspGraph->count_nodes + 1);
	add_node(part,tspGraph->nodes[start],0);

	//Chemin de la meilleure solution.
	Solution best = new_solution(tspGraph->count_nodes + 1);
	add_node(best,tspGraph->nodes[start],0);

	tspGraph->nodes[start]->colored = END;
	current = tspGraph->nodes[start];

	while(j < tspGraph->count_nodes) {
		while( current->subnodes[i] == NULL
			|| current->subnodes[i]->colored ==	UNVISITED) {
			++i;
		}
		add_node(best,current->subnodes[i],current->cost[i]);
		current->subnodes[i]->colored = VISITED_BNB;
		current = current->subnodes[i];
		++j;
	}
	i=0;
	while(current->subnodes[i]->name != start) {
		++i;
	}
	best->cost += current->cost[i];
	add_node(best,tspGraph->nodes[start],current->cost[i]);
	
	reset_coloration(tspGraph);
	tspGraph->nodes[start]->colored = END;

	//Affichage du premier chemin pour comparaison.
	print_solution(best);

	//Lancement de l'algo.
	Solution bst = branch_and_bound_rec_opti(part, best, tspGraph);


	//Affichage du meilleur chemin (à changer vers struct solution)
	print_solution(bst);

	return EXIT_SUCCESS;
}
