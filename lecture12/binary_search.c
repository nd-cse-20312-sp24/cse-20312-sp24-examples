/* Lecture 12 */

#include "search.h"
#include <stdio.h>

/* Functions */

bool binary_search(Array *array, int target) {
    int start = 0;              // Start of range to search
    int end = array->size - 1;  // End of range to search

    // Iterate as long as there are numbers in range to search
    while (start <= end) {
        // Compute midpoint of range
        int middle = (start + end) / 2;
        printf("start=%d  end=%d  middle=%d\n", start, end, middle);
        int midpoint = array->data[middle];

        // Check if target is found
        if (midpoint == target) 
            return true;

        // Adjust range
        if (midpoint > target)
            end = middle - 1;  // Go left
        else
            start = middle + 1;  // Go right
    }

    return false;
}

bool binary_search_r(Array *array, int target, int start, int end) {
    // Base case: no more numbers to search
    if (start > end)
    	return false;

    // Base case: we found target
    int middle   = (start + end) / 2;
    printf("start=%d  end=%d  middle=%d\n", start, end, middle);
    int midpoint = array->data[middle];
    if (midpoint == target)
	    return true;

    // Recursive: go left or right
    if (midpoint > target)
	    return binary_search_r(array, target, start, middle - 1);
    else
	    return binary_search_r(array, target, middle + 1, end);
}
