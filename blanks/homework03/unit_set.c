#include "set.h"
#include <stdio.h>
#include <assert.h>

bool test_00_set_create() {
    Set *set = set_create();
    assert(set->capacity == ARRAY_DEFAULT_CAPACITY);
    assert(set->size == 0);
    free(set->data);
    free(set);
    return EXIT_SUCCESS;
}

bool test_01_set_delete() {
    Set *set = set_create();
    set_delete(set);
    return EXIT_SUCCESS;
}

bool test_02_set_add() {
    Set *set = set_create();
    set_add(set, 100);
    assert(set->size == 1);
    assert(set->data[0] == 100);
    set_add(set, 200);
    assert(set->size == 2);
    assert(set->data[1] == 200);
    set_delete(set);
    return EXIT_SUCCESS;
}

bool test_03_set_contains() {
    Set *set = set_create();
    set_add(set, 100);
    set_add(set, 200);
    set_add(set, 300);
    assert(set_contains(set, 100) == true);
    assert(set_contains(set, 200) == true);
    assert(set_contains(set, 300) == true);
    assert(set_contains(set, 400) == false);
    set_delete(set);
    return EXIT_SUCCESS;
}

bool test_04_set_remove() {
    Set *set = set_create();
    set_add(set, 100);
    set_add(set, 200);
    set_add(set, 300);
    set_remove(set, 400);
    assert(set->size == 3);
    set_remove(set, 200);
    assert(set->size == 2);
    assert(set_contains(set, 200) == false);
    set_remove(set, 300);
    assert(set->size == 1);
    assert(set_contains(set, 300) == false);
    set_remove(set, 100);
    assert(set->size == 0);
    assert(set_contains(set, 100) == false);
    set_delete(set);
    return EXIT_SUCCESS;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
        fprintf(stderr, "Where NUMBER is one of the following:\n");
        fprintf(stderr, "    0  Test set_create\n");
        fprintf(stderr, "    1  Test set_delete\n");
        fprintf(stderr, "    2  Test set_add\n");
        fprintf(stderr, "    3  Test set_contains\n");
        fprintf(stderr, "    4  Test set_remove\n");
        return EXIT_FAILURE;
    }   

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
        case 0:  status = test_00_set_create();     break;
        case 1:  status = test_01_set_delete();     break;
        case 2:  status = test_02_set_add();        break;
        case 3:  status = test_03_set_contains();   break;
        case 4:  status = test_04_set_remove();     break;
        default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }
    
    return status;
}