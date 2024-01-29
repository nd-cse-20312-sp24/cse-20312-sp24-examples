/* Lecture 07: Dynamic Array */

#include "array.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    // Create Array
    Array* array = array_create();

    printf("array->size     = %lu\n", array->size);
    printf("array->capacity = %lu\n", array->capacity);

    // Append to Array
    array_append(array, 4);
    array_append(array, 6);
    array_append(array, 5);
    array_append(array, 5);
    array_append(array, 6);

    printf("array->size     = %lu\n", array->size);
    printf("array->capacity = %lu\n", array->capacity);

    // Access elements in Array
    for (size_t i = 0; i < array->size; i++) {
        printf("array[%lu] = %d\n", i, array_at(array, i));
    }

    // Search for elements in Array
    printf("array_index(4) = %ld\n", array_index(array, 4));
    printf("array_index(5) = %ld\n", array_index(array, 5));
    printf("array_index(6) = %ld\n", array_index(array, 6));
    printf("array_index(7) = %ld\n", array_index(array, 7));

    // Insert elements from Array
    array_insert(array, 0, 2);
    array_insert(array, 0, 1);
    array_insert(array, 2, 3);
    array_insert(array, 4, 5);

    printf("array->size     = %lu\n", array->size);
    printf("array->capacity = %lu\n", array->capacity);

    for (size_t i = 0; i < array->size; i++) {
        printf("array[%lu] = %d\n", i, array_at(array, i));
    }

    array_delete(array);
    return 0;
}
