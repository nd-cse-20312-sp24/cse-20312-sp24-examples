#include "array.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool test_00_array_create(){
    Array* array = array_create();
    assert(array->size == 0);
    assert(array->capacity == ARRAY_DEFAULT_CAPACITY);
    free(array->data);
    free(array);
    return EXIT_SUCCESS;
}

bool test_01_array_delete() {
    Array* array = array_create();
    array_delete(array);
    return EXIT_SUCCESS;
}

bool test_02_array_append() {
    Array* array = array_create();
    array_append(array, 100);
    array_append(array, 101);
    array_append(array, 102);
    array_append(array, 103);
    assert(array->size == 4);
    assert(array->capacity == 4);
    array_append(array, 104);
    assert(array->size == 5);
    assert(array->capacity == 8);
    assert(array->data[0] == 100);
    assert(array->data[1] == 101);
    assert(array->data[2] == 102);
    assert(array->data[3] == 103);
    assert(array->data[4] == 104);
    array_delete(array);
    return EXIT_SUCCESS;
}

bool test_03_array_at() {
    Array* array = array_create();
    array_append(array, 100);
    array_append(array, 101);
    array_append(array, 102);
    array_append(array, 103);
    array_append(array, 104);
    assert(array_at(array, 0) == 100);
    assert(array_at(array, 1) == 101);
    assert(array_at(array, 2) == 102);
    assert(array_at(array, 3) == 103);
    assert(array_at(array, 4) == 104);
    array_delete(array);
    return EXIT_SUCCESS;
}

bool test_04_array_index() {
    Array* array = array_create();
    array_append(array, 100);
    array_append(array, 101);
    array_append(array, 102);
    array_append(array, 103);
    array_append(array, 104);
    assert(array_index(array, 100) == 0);
    assert(array_index(array, 104) == 4);
    assert(array_index(array, 1000) == -1);
    array_delete(array);
    return EXIT_SUCCESS;
}

bool test_05_array_insert() {
    Array* array = array_create();
    array_append(array, 100);
    array_append(array, 101);
    array_append(array, 102);
    array_insert(array, 0, 1000);
    assert(array->size == 4);
    assert(array->capacity == 4);
    assert(array->data[0] == 1000);
    assert(array->data[1] == 100);
    assert(array->data[2] == 101);
    array_insert(array, 3, 1001);
    assert(array->size == 5);
    assert(array->capacity == 8);
    assert(array->data[3] == 1001);
    assert(array->data[4] == 102);
    array_delete(array);
    return EXIT_SUCCESS;
}

bool test_06_array_remove() {
    Array* array = array_create();
    array_append(array, 100);
    array_append(array, 101);
    array_append(array, 102);
    array_append(array, 103);
    array_remove(array, 0);
    assert(array->size == 3);
    assert(array->data[0] == 101);
    assert(array->data[2] == 103);
    array_remove(array, 1);
    assert(array->size == 2);
    assert(array->data[0] == 101);
    assert(array->data[1] == 103);
    array_remove(array, 1);
    assert(array->size == 1);
    assert(array->data[0] == 101);
    array_delete(array);
    return EXIT_SUCCESS;
}


/* Main Execution */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
        fprintf(stderr, "Where NUMBER is right of the following:\n");
        fprintf(stderr, "    0  Test array_create\n");
        fprintf(stderr, "    1  Test array_delete\n");
        fprintf(stderr, "    2  Test array_append\n");
        fprintf(stderr, "    3  Test array_at\n");
        fprintf(stderr, "    4  Test array_index\n");
        fprintf(stderr, "    5  Test array_insert\n");
        fprintf(stderr, "    6  Test array_remove\n");
        return EXIT_FAILURE;
    }   

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
        case 0:  status = test_00_array_create(); break;
        case 1:  status = test_01_array_delete(); break;
        case 2:  status = test_02_array_append(); break;
        case 3:  status = test_03_array_at();     break;
        case 4:  status = test_04_array_index();  break;
        case 5:  status = test_05_array_insert(); break;
        case 6:  status = test_06_array_remove(); break;
        default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }
    
    return status;
}