/* Lecture 21: bucket sort */

#include "array.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Constants */

#define NBUCKETS    (1<<10)

/* Functions */

int  intcmp(const void *a, const void *b) {
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return (*ia - *ib);
}

void bucket_sort(int *a, size_t n) {
    // Determine maximum value
    int max_value = a[0];
    for (size_t i = 1; i < n; i++)
    	if (a[i] > max_value)
    	    max_value = a[i];

    // Allocate buckets
    size_t bucket_size = max_value / NBUCKETS;
    Array** buckets    = calloc(NBUCKETS + 1, sizeof(Array *));
    for (size_t i = 0; i <= NBUCKETS; i++)
    	buckets[i] = array_create();

    // Distribute values into buckets
    for (size_t i = 0; i < n; i++)
    	array_append(buckets[a[i] / bucket_size], a[i]);

    // Sort buckets and copy values back to vector
    size_t index = 0;
    for (size_t b = 0; b <= NBUCKETS; b++) {
    	qsort(buckets[b]->data, buckets[b]->size, sizeof(int), intcmp);
    	for (size_t i = 0; i < buckets[b]->size; i++)
    	    a[index++] = buckets[b]->data[i];
    }

    for (size_t i = 0; i <= NBUCKETS; i++) {
    	array_delete(buckets[i]);
    }
    free(buckets);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int *numbers = malloc(NUMBERS_MAX*sizeof(int));
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    bucket_sort(numbers, NUMBERS_MAX);
    free(numbers);
    return 0;
}
