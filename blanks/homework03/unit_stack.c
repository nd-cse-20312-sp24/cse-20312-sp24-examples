#include "stack.h"
#include <stdio.h>
#include <assert.h>

bool test_00_stack_create() {
    Stack *stack = stack_create();
    assert(stack->capacity == ARRAY_DEFAULT_CAPACITY);
    assert(stack->size == 0);
    free(stack->data);
    free(stack);
    return EXIT_SUCCESS;
}

bool test_01_stack_delete() {
    Stack *stack = stack_create();
    stack_delete(stack);
    return EXIT_SUCCESS;
}

bool test_02_stack_push() {
    Stack *stack = stack_create();
    stack_push(stack, 100);
    stack_push(stack, 200);
    assert(stack->size == 2);
    assert(stack->data[0] == 100);
    assert(stack->data[1] == 200);
    stack_delete(stack);
    return EXIT_SUCCESS;
}

bool test_03_stack_pop() {
    Stack *stack = stack_create();
    stack_push(stack, 100);
    stack_push(stack, 200);
    stack_pop(stack);
    assert(stack->size == 1);
    assert(stack->data[0] == 100);
    stack_pop(stack);
    assert(stack->size == 0);
    stack_delete(stack);
    return EXIT_SUCCESS;
}

bool test_04_stack_top() {
    Stack *stack = stack_create();
    stack_push(stack, 100);
    assert(stack_top(stack) == 100);
    stack_push(stack, 200);
    assert(stack_top(stack) == 200);
    stack_delete(stack);
    return EXIT_SUCCESS;
}

bool test_05_stack_empty() {
    Stack *stack = stack_create();
    assert(stack_empty(stack) == true);
    stack_push(stack, 100);
    assert(stack_empty(stack) == false);
    stack_push(stack, 200);
    stack_pop(stack);
    stack_pop(stack);
    assert(stack_empty(stack) == true);
    stack_delete(stack);
    return EXIT_SUCCESS;
}


/* Main Execution */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
        fprintf(stderr, "Where NUMBER is one of the following:\n");
        fprintf(stderr, "    0  Test stack_create\n");
        fprintf(stderr, "    1  Test stack_delete\n");
        fprintf(stderr, "    2  Test stack_push\n");
        fprintf(stderr, "    3  Test stack_pop\n");
        fprintf(stderr, "    4  Test stack_top\n");
        fprintf(stderr, "    5  Test stack_empty\n");
        return EXIT_FAILURE;
    }   

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
        case 0:  status = test_00_stack_create(); break;
        case 1:  status = test_01_stack_delete(); break;
        case 2:  status = test_02_stack_push();   break;
        case 3:  status = test_03_stack_pop();    break;
        case 4:  status = test_04_stack_top();    break;
        case 5:  status = test_05_stack_empty();  break;
        default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }
    
    return status;
}