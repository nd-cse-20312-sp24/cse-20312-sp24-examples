/* Lecture 15: bubble sort */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Functions */

void bubble_sort(int *a, int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1;  i < n;  i++) {
            if (a[i] < a[i - 1]) {
                swap(&a[i], &a[i - 1]);
                swapped = true;
                dump_array(a, n);
            }
        }
    } while (swapped);
}

void bubble_sort_anim(int *a, int n) {
    for (int i = n - 1;  i > 0;  i--) {
        for (int j = 0;  j < i;  j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
                dump_array(a, n);
            }
        }
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int a[] = {5, 4, 3, 2, 1};
    int alen = sizeof(a) / sizeof(int);

    dump_array(a, alen);
    bubble_sort_anim(a, alen);
    return 0;
}
