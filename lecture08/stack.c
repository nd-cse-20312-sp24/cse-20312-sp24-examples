/* Lecture 08: Stack (Dynamic Array) */

#include "stack.h"

/* Functions */

Stack* stack_create() {
    return array_create();
}

void stack_delete(Stack *stack) {
    array_delete(stack);
}

void stack_push(Stack *s, int value) {
    array_append(s, value);
}

int	stack_pop(Stack *s) {
    int top = stack_top(s);
    s->size--;
    return top;
}

int	stack_top(Stack *s) {
    return array_at(s, s->size - 1);
}

bool stack_empty(Stack *s) {
    return s->size == 0;
}
