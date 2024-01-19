/* duplicates1.c: simple version */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "library.h"

/* Functions */

bool has_duplicates(int *array, size_t n) {
    // Time:	O(n^2)
    // Space:	O(1)
    for (size_t i = 0; i < n; i++)
	for (size_t j = i + 1; j < n; j++)  // Demo: j = i (use gdb to trace)
	    if (array[i] == array[j])
	    	return true;
    return false;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int numbers[NUMBERS_MAX] = {0};
    srand(time(NULL));	// Demo: Forget this?
    make_random_array(numbers, NUMBERS_MAX);
    puts(has_duplicates(numbers, NUMBERS_MAX) ? "Yeah" : "Nope");
    return 0;
}
