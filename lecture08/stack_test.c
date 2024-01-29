/* Lecture 08: Stack (Dynamic Array) */

#include "stack.h"

#include <assert.h>
#include <stdio.h>

/* Main Execution */

int main(int arg, char *argv[]) {
    Stack *s = stack_create();

    stack_push(s, 4);
    stack_push(s, 3);
    stack_push(s, 2);
    stack_push(s, 1);
    stack_push(s, 0);

    assert(s->size == 5);
    assert(stack_top(s) == 0);

    while (!stack_empty(s)) {
    	printf("%d\n", stack_pop(s));
    }

    stack_delete(s);
    return 0;
}
