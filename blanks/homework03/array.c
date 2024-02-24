/* Lecture 07: Dynamic Array */

#include "array.h"

#include <assert.h>
#include <string.h>

/* Functions */

Array *array_create() {
    // Allocate Array structure, exit if it fails
    Array *array = malloc(sizeof(Array));
    assert(array);

    // Initialize capacity and size
    array->capacity = ARRAY_DEFAULT_CAPACITY;
    array->size = 0;

    // Allocate the data array, exit if it fails
    array->data = calloc(array->capacity, sizeof(int));
    assert(array->data);

    // return pointer to Array
    return array;
}

void array_delete(Array *array) {
    // Free the data array
    free(array->data);

    // Free the Array structure
    free(array);
}

void array_append(Array *array, int value) {
    // If the size is at capacity, double the capacity, exit if it fails
    if (array->size == array->capacity) {
        array->capacity *= 2;  // Double the capacity
        array->data = realloc(array->data, array->capacity * sizeof(int));
        assert(array->data);
    }

    // Store value at end of array and increment size
    array->data[array->size] = value;
    array->size++;
}

int array_at(Array *array, int index) {
    // Make sure index is in bounds
    assert(index < array->size && index >= 0);
    // Return the value at the index
    return array->data[index];
}

int array_index(Array *array, int value) {
    // Scan internal array for first element
    // that matches value and return its index         
    for (int index = 0; index < array->size; index++)
        if (array->data[index] == value) {
            return index;
        }

    // Return -1 if no match found
    return -1;
}

void array_insert(Array *array, int index, int value) {
    // Make sure index is in bounds
    assert(index < array->size && index >= 0);
    // If the size is at capacity, double the capacity, exit if it fails
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(int));
        assert(array->data);
    }

    // Compute how many bytes we need to shift right
    // (ie. # of elements x size of each element)
    int bytes = (array->size - index) * sizeof(int);

    // Move elements after insert from current index to the next index
    memmove(array->data + index + 1, array->data + index, bytes);

    // Store new value
    array->data[index] = value;
    array->size++;
}

void array_remove(Array *array, int index) {
    // Removed the element at index, shifting elements that follow to the left
    // TODO:
}
