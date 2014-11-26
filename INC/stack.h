//----------------------------------------------------------
// AUTEURS : REYNAUD Nicolas, BASCOL Kevin                  |
// FICHIER : stack.h                                        |
// DATE : 25/11/14                                          |
//----------------------------------------------------------

#ifndef _STACK_
#define _STACK_

#include "struct_graph.h"

typedef struct Stack_node {
  Node node;
  struct Stack_node *next;
} Stack_node;

Stack_node* stack_new();

int stack_empty(Stack_node* stack);

void stack_free(Stack_node* stack);

void stack_push(Stack_node* stack, Node n);

Stack_node* stack_copy(Stack_node* stack);

Node stack_pop(Stack_node* stack);

void stack_print(Stack_node* stack);

#endif /* _STACK_ INCLUDED */
