/* Lecture 15: Utilities */

#include "utils.h"

#include <stdio.h>

/* Functions */

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void dump_array(int *a, int n) {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
	printf(" %d", a[i]);
    printf("\n");
}
