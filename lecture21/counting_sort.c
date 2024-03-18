/* Lecture 21: counting sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Functions */

void counting_sort(int *a, size_t n) {
    // Determine maximum value
    int max_value = a[0];
    for (size_t i = 1; i < n; i++)
    	if (a[i] > max_value)
    	    max_value = a[i];

    // Allocate counts
    int *counts = calloc(max_value + 1, sizeof(int));

    // Count occurrences
    for (size_t i = 0; i < n; i++)
    	counts[a[i]]++;

    // Updating original array
    size_t index = 0;
    for (size_t i = 0; i <= max_value; i++)
    	for (size_t c = 0; c < counts[i]; c++)
    	    a[index++] = i;

    free(counts);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int *numbers = malloc(NUMBERS_MAX*sizeof(int));
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    counting_sort(numbers, NUMBERS_MAX);
    free(numbers);
    return 0;
}
