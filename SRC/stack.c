//----------------------------------------------------------
// AUTEURS : REYNAUD Nicolas, BASCOL Kevin                  |
// FICHIER : stack.c                                        |
// DATE : 25/11/14                                          |
//----------------------------------------------------------

#include <stdlib.h>
#include "stack.h"
#include "error.h"


Stack_node* stack_new() {
	Stack_node *stack = malloc(sizeof *stack);
	
	if(stack == NULL) {
		DEBUG_PRINTF("Can't allocate newNode");
		QUIT_MSG("Can't allocate newNode");
  	}
  	
  	return stack;
}

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

void stack_push(Stack_node* stack, Node n) {
	Stack_node *newNode = malloc(sizeof *newNode);

	if(newNode == NULL) {
		DEBUG_PRINTF("Can't allocate newNode");
		QUIT_MSG("Can't allocate newNode");
  	}

	newNode->next = stack;
	newNode->node = n;
	stack = newNode;
	
	return;
}

Stack_node* stack_copy(Stack_node* stack) {
	Stack_node* newStack = stack_new();
	newStack->next = NULL;
	newStack->node = stack->node;
	
	Stack_node* current = stack->next;
	 
	while(current != NULL){
		newStack->next = newStack;
		newStack->node = current->node;
		current = current->next;
	}
	
	return newStack;
}

Node stack_pop(Stack_node* stack) {
	Node n = NULL;
	if(!stack_empty(stack)){
		n = stack->node;
		stack = stack->next;
	}
	return n;
}

void stack_print(Stack_node* stack) {
	Stack_node* current = stack;

	while(!stack_empty(current)){
		printf("- node %d\n",current->node->name);
		current = current->next;
	}
}
