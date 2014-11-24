//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_opti.c                             |
// DATE : 28/10/14                                          |
//----------------------------------------------------------

#include "branch_and_bound_opti.h"


Solution branch_and_bound_rec_opti(Solution part, Solution best, Graph tspGraph) {
	int cost = 0,i, j;
	if(part->count_nodes_s == best->count_nodes_s -1){
	
		cost = part->cost + part->list_node[part->count_nodes_s-1]->cost[0];
		printf("cost nb = np : %d\n",cost);
		if(cost < best->cost) {
			best = copy_solution(part);
			add_node(best, part->list_node[0],part->list_node[part->count_nodes_s-1]->cost[0]);
		}
		
		printf("best:");print_solution(best);
	}
	else{
		for(j=0; j < tspGraph->count_nodes; ++j) {
			printf("	-j = %d",j);
		
			int last = part->count_nodes_s-1;
			
			if( part->list_node[last]->subnodes[j] != NULL
			 && part->list_node[last]->subnodes[j]->colored == UNVISITED) {

				cost = part->cost + part->list_node[last]->cost[j];
				
				if(cost < best->cost) {
				
					add_node(part,part->list_node[last]->subnodes[j],part->list_node[last]->cost[j]);
					
					printf("part:");print_solution(part);
					
					part->list_node[last]->subnodes[j]->colored = VISITED_BNB;
					
					i = 0;
					Solution newPart = new_solution(tspGraph->count_nodes + 1 );

					for ( i = 0; i < part->count_nodes_s; i++) {
						newPart->list_node[i] = part->list_node[i];
					}

					newPart->cost = part->cost;
					newPart->count_nodes_s = part->count_nodes_s;
					
					best = branch_and_bound_rec_opti(newPart, best, tspGraph);
					free_solution(newPart);
					part->list_node[last]->subnodes[j]->colored = UNVISITED;
				}
			}
		}
	}
	return best;
}

Solution branch_and_bound_opti(Graph tspGraph) {
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
		while(i == current->name || (current->subnodes[i]->colored != UNVISITED &&current->subnodes[i]->colored != END)) {
			++i;
		}
		add_node(best,current->subnodes[i],current->cost[i]);
		current->subnodes[i]->colored = VISITED_BNB;
		current = current->subnodes[i];
		++j;
	}	
	add_node(best,tspGraph->nodes[start],current->cost[start]);
	
	// Remise à VISITED_BNB des noeuds, sauf le premier.
	reset_coloration(tspGraph);
	tspGraph->nodes[start]->colored = END;

	//Affichage du premier chemin pour comparaison.
	print_solution(best);

	//Lancement de l'algo.
	
	Solution result = branch_and_bound_rec_opti(part, best, tspGraph);
	free_solution(part);
	free_solution(best);
	
	return result;
}
