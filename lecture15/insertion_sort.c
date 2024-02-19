/* Lecture 15: insertion sort */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Functions */

void insertion_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i;  j > 0 && a[j] < a[j - 1];  j--) {
            swap(&a[j], &a[j - 1]);
        }
        dump_array(a, n);
    }
}

void insertion_sort_anim(int *a, int n) {
    for (int i = 1;  i < n;  i++) {
        int j = i - 1;
        while ((j >= 0) && (a[j] > a[j+1])) {
            swap(&a[j], &a[j+1]);
            j = j - 1;
        }
        dump_array(a, n);
    }
}

void insertion_sort_anim_improved(int *a, int n) {
    for (int i = 1;  i < n;  i++) {
        int j = i - 1;
        int tmp = a[i];
        while ((j >= 0) && (a[j] > tmp)) {
            swap(&a[j], &a[j+1]);
            j = j - 1;
        }
        a[j+1] = tmp;
        dump_array(a, n);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int a[] = {5, 4, 3, 2, 1};
    int alen = sizeof(a) / sizeof(int);

    dump_array(a, alen);
    insertion_sort_anim(a, alen);
    return 0;
}
