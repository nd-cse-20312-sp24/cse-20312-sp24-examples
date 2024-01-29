/* Lecture 07: Dynamic Array */

#include "array.h"

#include <assert.h>
#include <string.h>

/* Constants */

const size_t ARRAY_DEFAULT_CAPACITY = 1<<2;

/* Functions */

Array*  array_create() {
    // Allocate Array structure
    Array *array = malloc(sizeof(Array));

    // Initialize Array attributes
    if (array) {
        array->capacity = ARRAY_DEFAULT_CAPACITY;
        array->size     = 0;
        array->data     = calloc(array->capacity, sizeof(int));
        if (!array->data) {
            free(array);
            return NULL;
        }
    }

    return array;
}

void    array_delete(Array *array) {
    // Release internal allocations
    free(array->data);
    // Release Array structure
    free(array);
}

void    array_append(Array *array, int value) {
    // Resize if necessary
    if (array->size == array->capacity) {
        array->capacity *= 2;   // Double the capacity
        array->data      = realloc(array->data, array->capacity*sizeof(int));
    }

    // Store value at end of array
    array->data[array->size] = value;
    array->size++;
}

int     array_at(Array *array, size_t index) {
    // Make sure we only access valid elements
    assert(index < array->size);
    return array->data[index];
}

ssize_t array_index(Array *array, int value) {
    // Scan internal array for first element that matches value            
    for (size_t index = 0; index < array->size; index++)
        if (array->data[index] == value)
            return index;

    return -1;
}

void    array_insert(Array *array, size_t index, int value) {
    // Make sure we are within bounds
    assert(index <= array->size);

    // Resize if necessary
    if (array->size == array->capacity) {
        array->capacity *= 2;   // Double the capacity
        array->data      = realloc(array->data, array->capacity*sizeof(int));
    }

    // Compute how many bytes we need to shift
    // (ie. # of elements x size of each element)
    size_t bytes = (array->size - index)*sizeof(int);
    // Move elements from current index to the next index
    memmove(array->data + index + 1, array->data + index, bytes);
    // Store new value
    array->data[index] = value;
    array->size++;
}

