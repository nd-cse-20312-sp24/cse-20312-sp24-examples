// define a struct for a typedef for a dynamic array of integers with attributes for capacity and size and a dynamically allocated array of data


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vector.h"

// define a struct for a typedef for a dynamic array of integers with attributes for capacity and size and a dynamically allocated array of data    

// create a new vector
Vector* vector_new() {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->capacity = 1;
    v->size = 0;
    v->data = (int*)malloc(sizeof(int) * v->capacity);
    return v;
}

// free the memory allocated for the vector
    