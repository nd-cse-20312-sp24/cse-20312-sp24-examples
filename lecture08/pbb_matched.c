/* Lecture 08: PBB-Matched */

#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Functions */

bool	is_pbb_matched(const char *s) {
    Stack *stack  = stack_create();
    bool   result = false;

    for (const char *c = s; *c; c++) {
    	if (*c == '(' || *c == '{' || *c == '[') {  // Case: Add opening to stack
    	    stack_push(stack, *c);
	} else {				    // Case: Check closing to top of stack
	    if (stack_empty(stack) ||		    // Case: Handle if more closing than opening
	    	(*c == ')' && stack_top(stack) != '(') ||
	    	(*c == '}' && stack_top(stack) != '{') ||
	    	(*c == ']' && stack_top(stack) != '[')
	    )
	    	goto finish;

	    stack_pop(stack);
	}
    }

    result = stack_empty(stack);		    // Case: Handle if more opening than closing

finish:
    stack_delete(stack);
    return result;
}

/* Main Execution */

int	main(int argc, char *argv[]) {
    char buffer[BUFSIZ];

    while (fgets(buffer, BUFSIZ, stdin)) {
    	buffer[strlen(buffer) - 1] = 0;

    	puts(is_pbb_matched(buffer) ? "YEAH" : "NOPE");
    }

    return 0;
}
