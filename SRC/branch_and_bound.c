//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound.c                             |
// DATE : 28/10/14                                          |
//----------------------------------------------------------

#include "branch_and_bound.h"


Solution branch_and_bound_rec(Solution part, Solution best, Graph tspGraph) {
	int cost = 0,i, j;
	if(part->count_nodes_s == best->count_nodes_s -1){
	
		cost = part->cost + part->list_node[part->count_nodes_s-1]->cost[0];
		if(cost < best->cost) {
			for ( i = 0; i < part->count_nodes_s; i++) {
				best->list_node[i] = part->list_node[i];
			}

			best->cost = part->cost;
			best->count_nodes_s = part->count_nodes_s;
			
			add_node(best, part->list_node[0],part->list_node[part->count_nodes_s-1]->cost[0]);
		}
	}
	else{
		for(j=0; j < tspGraph->count_nodes; ++j) {
			int last = part->count_nodes_s-1;
			
			if( part->list_node[last]->subnodes[j] != NULL
			 && part->list_node[last]->subnodes[j]->colored == UNVISITED) {

				cost = part->cost + part->list_node[last]->cost[j];
				
				if(cost < best->cost) {
				
					add_node(part,part->list_node[last]->subnodes[j],part->list_node[last]->cost[j]);
					
					part->list_node[last]->subnodes[j]->colored = VISITED_BNB;
					
					i = 0;
					Solution newPart = new_solution(tspGraph->count_nodes + 1 );

					for ( i = 0; i < part->count_nodes_s; i++) {
						newPart->list_node[i] = part->list_node[i];
					}

					newPart->cost = part->cost;
					newPart->count_nodes_s = part->count_nodes_s;
					
					best = branch_and_bound_rec(newPart, best, tspGraph);
					
					free_solution(newPart);
					
					part->list_node[last]->subnodes[j]->colored = UNVISITED;
					--part->count_nodes_s;
					part->cost -= part->list_node[last]->cost[j];
					part->list_node[last+1]=NULL;
				}
			}
		}
	}
	return best;
}

Solution branch_and_bound(Graph tspGraph) {
	int start = 0; 
	int i = 0, j = 1;
	Node current = NULL; 

	Solution part = new_solution(tspGraph->count_nodes + 1);
	add_node(part,tspGraph->nodes[start],0);

	Solution best = new_solution(tspGraph->count_nodes + 1);
	add_node(best,tspGraph->nodes[start],0);

	tspGraph->nodes[start]->colored = END;
	current = tspGraph->nodes[start];
	
	// Find the first path that come to use as "best" solution.
	while(j < tspGraph->count_nodes) {
		while(i == current->name || (current->subnodes[i]->colored == VISITED_BNB &&current->subnodes[i]->colored != END)) {
			++i;
		}
		add_node(best,current->subnodes[i],current->cost[i]);
		current->subnodes[i]->colored = VISITED_BNB;
		current = current->subnodes[i];
		++j;
	}	
	add_node(best,tspGraph->nodes[start],current->cost[start]);
	
	reset_coloration(tspGraph);
	tspGraph->nodes[start]->colored = END;

	// Launch of the recursive algorithm.	
	Solution result = branch_and_bound_rec(part, best, tspGraph);

	free_solution(part);
	
	return result;
}
