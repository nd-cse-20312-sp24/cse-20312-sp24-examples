/* Lecture 15: insertion sort */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Functions */

void insertion_sort_anim(int *a, int n) {
    int swaps = 0;
    int compares = 0;
    for (int i = 1;  i < n;  i++) {
        int j = i - 1;
        while ((j >= 0) && (a[j] > a[j+1])) {
            swap(&a[j], &a[j+1]);
            j = j - 1;
        }
        // dump_array(a, n);
    }
    printf("compares: %d   swaps: %d\n", compares, swaps);
}

void insertion_sort_anim_improved(int *a, int n) {
    for (int i = 1;  i < n;  i++) {
        int j = i - 1;
        int tmp = a[i];
        while ((j >= 0) && (a[j] > tmp)) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = tmp;
        // dump_array(a, n);
    }
}

// void insertion_sort_anim_improved(int *a, int n) {
//     int swaps = 0;
//     int compares = 0;
//     for (int i = 1; i < n; i++) {
//         int j = i - 1;
//         int tmp = a[i];
//         while (j >= 0) {
//             compares++;
//             if (a[j] > tmp) {
//                 a[j + 1] = a[j];
//                 swaps++;
//                 j = j - 1;
//             } else {
//                 break;
//             }
//         }
//         a[j + 1] = tmp;
//         // dump_array(a, n);
//     }
//     printf("compares: %d   writes: %d\n", compares, swaps);
// }

/* Main Execution */

int main(int argc, char *argv[]) {
    // int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int alen = sizeof(a) / sizeof(int);

    // dump_array(a, alen);
    insertion_sort_anim_improved(a, alen);
    // dump_array(a, alen);
   return 0;
}
