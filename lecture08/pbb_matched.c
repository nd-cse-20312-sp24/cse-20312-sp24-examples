/* Lecture 08: PBB-Matched */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

/* Functions */

bool is_pbb_matched(char *s) {
    Stack *stack = stack_create();

    for (char *c = s; *c; c++) {
        // if char is an opener, push 
        if (*c == '{' || *c == '[' || *c == '(') {
            stack_push(stack, *c);
        // else if char is a closer that match opener on stack, pop
        } else if ((*c == '}' && stack_top(stack) == '{') ||
                   (*c == ']' && stack_top(stack) == '[') ||
                   (*c == ')' && stack_top(stack) == '(')) {
            stack_pop(stack);
        // else no match
        } else {
            stack_delete(stack);
            return false;
        }
    }
    if (stack_empty(stack)) {
        stack_delete(stack);
        return true;
    } else {
        stack_delete(stack);
        return false;
    }
}

int main(int argc, char *argv[]) {
    char buffer[BUFSIZ];

    while (fgets(buffer, BUFSIZ, stdin)) {
        buffer[strlen(buffer) - 1] = 0;

        puts(is_pbb_matched(buffer) ? "YEAH" : "NOPE");
    }

    return 0;
}