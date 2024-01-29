/* Lecture 08: Stack (Dynamic Array) */

#pragma once

#include "array.h"

/* Structures */

typedef Array Stack;

/* Macros */

#define	stack_create()	array_create()
#define	stack_delete(s)	array_delete(s)

/* Functions */

void	stack_push(Stack *s, int value);
int	stack_pop(Stack *s);
int	stack_top(Stack *s);
bool	stack_empty(Stack *s);
