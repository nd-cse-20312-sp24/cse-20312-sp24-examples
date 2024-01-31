#include "array.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* mashing all the unit tests into one function */

int main() {
    // test array_create
    Array* array = array_create();
    assert(array->size == 0);
    assert(array->capacity == 4);

    // test array_append
    array_append(array, 100);
    array_append(array, 101);
    array_append(array, 102);
    array_append(array, 103);
    assert(array->size == 4);
    assert(array->capacity == 4);

    array_append(array, 104);
    assert(array->size == 5);
    assert(array->capacity == 8);

    // test array_at
    assert(array_at(array, 0) == 100);
    assert(array_at(array, 2) == 102);
    assert(array_at(array, 4) == 104);

    // test array_index
    assert(array_index(array, 100) == 0);
    assert(array_index(array, 102) == 2);
    assert(array_index(array, 104) == 4);

    // test array_insert
    array_insert(array, 0, 1000);
    array_insert(array, 0, 1001);
    array_insert(array, 2, 1002);
    array_insert(array, 4, 1003);
    assert(array->size == 9);
    assert(array->capacity == 16);
    assert(array_at(array, 0) == 1001);
    assert(array_at(array, 1) == 1000);
    assert(array_at(array, 2) == 1002);
    assert(array_at(array, 3) == 100);
    assert(array_at(array, 4) == 1003);
    assert(array_at(array, 8) == 104);

    array_delete(array);

    puts("Passed all asserts");
    return EXIT_SUCCESS;
}