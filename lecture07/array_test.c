/* Lecture 07: Dynamic Array */

#include "array.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    // Create Array
    Array* array = array_create();

    puts("---- Initial size and capacity");
    printf("array->size     = %d\n", array->size);
    printf("array->capacity = %d\n", array->capacity);

    // Append to Array
    array_append(array, 100);
    array_append(array, 101);
    array_append(array, 102);
    array_append(array, 103);

    puts("---- Size and capacity after 4 appends");
    printf("array->size     = %d\n", array->size);
    printf("array->capacity = %d\n", array->capacity);

    array_append(array, 104);

    puts("---- Size and capacity after 5th append");
    printf("array->size     = %d\n", array->size);
    printf("array->capacity = %d\n", array->capacity);

    // Access elements in Array
    puts("---- Loop over full array using array_at");
    for (int i = 0; i < array->size; i++) {
        printf("array[%d] = %d\n", i, array_at(array, i));
    }

    // Search for elements in Array
    puts("---- Testing array_index");
    printf("array_index(100) = %d\n", array_index(array, 100));
    printf("array_index(102) = %d\n", array_index(array, 102));
    printf("array_index(104) = %d\n", array_index(array, 104));

    // Insert elements from Array
    array_insert(array, 0, 1000);
    array_insert(array, 0, 1001);
    array_insert(array, 2, 1002);
    array_insert(array, 4, 1003);

    puts("---- After 4 array inserts");
    printf("array->size     = %d\n", array->size);
    printf("array->capacity = %d\n", array->capacity);

    puts("---- Loop over full array using array_at");
    for (int i = 0; i < array->size; i++) {
        printf("array[%d] = %d\n", i, array_at(array, i));
    }

    array_delete(array);
    return 0;
}
