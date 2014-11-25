//----------------------------------------------------------
// AUTEURS : REYNAUD Nicolas, BASCOL Kevin                  |
// FICHIER : stack.c                                        |
// DATE : 25/11/14                                          |
//----------------------------------------------------------

#include <stdlib.h>
#include "stack.h"

int stack_empty(Stack_node* stack) {
	if(stack == NULL){
		return 1;
	}
	return 0;
}

void stack_free(Stack_node* stack) {
	Stack_node *node;

	for(node = stack; stack != NULL; node = stack) {
		stack = stack->next;
		free(node);
	}
}

int stack_push(Stack_node* stack, Node n, int nbNode) {
	Stack_node *newNode = malloc(sizeof *newNode);

	if(newNode == NULL) {
		DEBUG_PRINTF("Can't allocate newNode");
		QUIT_MSG("Can't allocate newNode");
  	}

	newNode->next = stack;
	newNode->node = n;
	stack = newNode;
	
	return ++nbNode;
}

int stack_pop(Stack_node* stack, Node n, int nbNode) {	
	if(!stack_empty(stack)){
		Stack_node *rest = stack->next;
		n = stack->node;
		free(stack);
		stack = rest;
		--nbNode;
	}
  
	return nbNode;
}
