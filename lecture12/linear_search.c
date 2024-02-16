/* Lecture 12 */

#include "search.h"
#include <stdio.h>

/* Functions */

bool linear_search(Array *array, int target) {
    // Iterate through each item in array and check against target
    for (int i = 0; i < array->size; i++)
    	if (array->data[i] == target)
    	    return true;
    return false;
}

bool linear_search_r(Array *array, int target, int index) {
    // Base case: we reach end of array
    if (index >= array->size)
    	return false;

    // Base case: we found target
    if (array->data[index] == target)
	    return true;

    // Recursive: check next item
    return linear_search_r(array, target, index + 1);
}
