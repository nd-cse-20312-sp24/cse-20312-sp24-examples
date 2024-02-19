/* Lecture 15: bubble sort */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Functions */

void bubble_sort_anim(int *a, int n) {
    int swaps = 0;
    int compares = 0;
    for (int i = n - 1;  i > 0;  i--) {
        for (int j = 0;  j < i;  j++) {
            compares++;
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
                swaps++;
                // dump_array(a, n);
            }
        }
    }
    printf("compares: %d   swaps: %d\n", compares, swaps);
}

void bubble_sort_end_early(int *a, int n) {
    int swaps = 0;
    int compares = 0;
    bool swapped;
    do {
        swapped = false;
        for (int i = 1;  i < n;  i++) {
            compares++;
            if (a[i] < a[i - 1]) {
                swap(&a[i], &a[i - 1]);
                swaps++;
                swapped = true;
                // dump_array(a, n);
            }
        }
    } while (swapped);
    printf("compares: %d   swaps: %d\n", compares, swaps);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    // int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int alen = sizeof(a) / sizeof(int);

    // dump_array(a, alen);
    bubble_sort_end_early(a, alen);
    return 0;
}
