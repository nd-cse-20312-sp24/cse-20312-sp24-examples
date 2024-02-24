#pragma once

#include <stdbool.h>
#include <stdlib.h>

/* Constants */
#define ARRAY_DEFAULT_CAPACITY 1 << 2

/* Structure */

typedef struct {
    int	  *data;	// Internal array
    int   capacity;	// Total number of elements
    int   size;	// Number of valid elements
} Array;

/* Functions */

Array*	array_create();
void	array_delete(Array *array);
void	array_append(Array *array, int value);
int	    array_at(Array *array, int index);
int	    array_index(Array *array, int value);
void	array_insert(Array *array, int index, int value);
void    array_remove(Array *array, int index);
