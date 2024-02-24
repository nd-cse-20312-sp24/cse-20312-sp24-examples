#pragma once

#include "array.h"

/* Structures */

typedef Array Stack;

/* Functions */

Stack*  stack_create();
void	stack_delete(Stack *stack);
void    stack_push(Stack *stack, int value);
int	    stack_pop(Stack *stack);
int     stack_top(Stack *stack);
bool	stack_empty(Stack *stack);
