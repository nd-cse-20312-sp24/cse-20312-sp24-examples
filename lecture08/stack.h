/* Lecture 08: Stack (Dynamic Array) */

#pragma once

#include "array.h"

/* Structures */

typedef Array Stack;

/* Functions */

Stack*  stack_create();
void	stack_delete(Stack *stack);
void    stack_push(Stack *s, int value);
int	    stack_pop(Stack *s);
int     stack_top(Stack *s);
bool	stack_empty(Stack *s);
