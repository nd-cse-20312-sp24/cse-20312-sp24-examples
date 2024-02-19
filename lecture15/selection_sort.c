/* Lecture 15: selection sort */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Functions */

void selection_sort(int *a, int n) {
    for (int i = 0;  i < (n - 1);  i++) {
        int j_min = i;
        for (int j = i + 1;  j < n;  j++)
            if (a[j] < a[j_min]) 
                j_min = j;
        swap(&a[i], &a[j_min]);
        dump_array(a, n);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int a[] = {5, 4, 3, 2, 1};
    int alen = sizeof(a) / sizeof(int);

    dump_array(a, alen);
    selection_sort(a, alen);
    return 0;
}
