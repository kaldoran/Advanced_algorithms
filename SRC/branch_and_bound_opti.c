//----------------------------------------------------------
// AUTEUR : BASCOL Kevin                                    |
// FICHIER : branch_and_bound_opti.c                        |
// DATE : 28/10/14                                          |
//----------------------------------------------------------

#include "branch_and_bound_opti.h"



Solution branch_and_bound_rec_opti(Solution part, Solution best, Graph tspGraph, Stack_node* stack) {
	int cost = 0, i;
	if(part->count_nodes_s == best->count_nodes_s -1){
	
		cost = part->cost + part->list_node[part->count_nodes_s-1]->cost[0];
		if(cost < best->cost) {
			best = copy_solution(part);
			add_node(best, part->list_node[0],part->list_node[part->count_nodes_s-1]->cost[0]);
		}
		printf("<--- Best\n");print_solution(best);printf("\n--->\n");
	}
	else{
		while(!stack_empty(stack)){			
			int last = part->count_nodes_s-1;
		
			printf("<--- last = %d\n",last);stack_print(stack);printf("\n--->\n");
			
			Node current = stack_pop(stack);
			
			cost = part->cost + part->list_node[last]->cost[current->name];
			if(cost < best->cost) {
				add_node(part,part->list_node[last]->subnodes[current->name],part->list_node[last]->cost[current->name]);
				print_solution(part);
				
				i = 0;
				Solution newPart = new_solution(tspGraph->count_nodes + 1 );

				for ( i = 0; i < part->count_nodes_s; i++) {
					newPart->list_node[i] = part->list_node[i];
				}

				newPart->cost = part->cost;
				newPart->count_nodes_s = part->count_nodes_s;
				
				//Stack_node* newStack = stack_copy(stack->next);
					
				best = branch_and_bound_rec_opti(newPart, best, tspGraph, /*newStack*/stack->next);
					
				free_solution(newPart);
				
				stack_push(stack,current);
				
				--part->count_nodes_s;
				part->cost -= part->list_node[last]->cost[current->name];
				part->list_node[last+1]=NULL;
			}
		}
	}
	return best;
}

Solution branch_and_bound_opti(Graph tspGraph) {
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
	
	Stack_node* stack = NULL;
	for(i = 0; i < tspGraph->count_nodes; ++i) {
		if(i != start) {
			Stack_node* newNode = stack_new();
			newNode->next = stack;
			newNode->node = tspGraph->nodes[i];
			stack = newNode;
		}
	}
	
	printf("<--- First Best\n");print_solution(best);printf("\n--->\n");
	
	// Launch of the recursive algorithm.	
	Solution result = branch_and_bound_rec_opti(part, best, tspGraph, stack);

	free_solution(part);
	free_solution(best);
	
	return result;
}
