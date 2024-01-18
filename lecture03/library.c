/* library.c */

#include "library.h"

/* Functions */

void make_random_array(int *array, size_t n) {
    for (size_t i = 0; i < n; i++) {
    	array[i] = rand() % (n*n);
    }
}
