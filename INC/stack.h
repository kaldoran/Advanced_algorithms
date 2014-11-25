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

int stack_empty(Stack_node* stack);

void stack_free(Stack_node* stack);

int stack_push(Stack_node* stack, Node n, int nbNode);

int stack_pop(Stack_node* stack, Node n, int nbNode);

#endif /* _STACK_ INCLUDED */
