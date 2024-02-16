bool linear_search(Array *array, int target) {
    for (each element i in array) {
        if (data[i] matches) {
            return true
        }
    }
    return false
}

bool linear_search_r(Array *array, int target, int index) {
    // Base case: we reach end of array
    if (end of array)
    	return false;

    // Base case: we found target
    if (data[i] matches target)
	    return true;

    // Recursive: linear search starting from index + 1
    return linear_search_r(array, target, index + 1);
}

bool binary_search(Array *array, int target) {
    set the start of the range to search
    set the end of the range to search

    // Iterate as long as there are numbers in range to search
    while (start <= end) {
        // Compute midpoint of range
        get the middle index
        get the midpoint value at middle

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
    get the middle index
    get the midpoint value at middle
    if (midpoint == target)
	    return true;

    // Recursive: go left or right
    if (midpoint > target)
	    return binary_search_r(array, target, start, middle - 1);
    else
	    return binary_search_r(array, target, middle + 1, end);
}



