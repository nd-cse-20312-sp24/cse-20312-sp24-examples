/* Lecture 15: selection sort */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Functions */

void selection_sort(int *a, int n) {
    int swaps = 0;
    int compares = 0;
    for (int i = 0; i < (n - 1); i++) {
        int j_min = i;
        for (int j = i + 1; j < n; j++) {
            compares++;
            if (a[j] < a[j_min]) {
                j_min = j;
            }
        }
        swap(&a[i], &a[j_min]);
        swaps++;
        // dump_array(a, n);
    }
    printf("compares: %d   swaps: %d\n", compares, swaps);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    // int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int alen = sizeof(a) / sizeof(int);

    // dump_array(a, alen);
    selection_sort(a, alen);
    return 0;
}
