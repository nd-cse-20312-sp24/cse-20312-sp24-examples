#include <stdbool.h>
#include <stdlib.h>

#include "duplicates.h"

// O(n^2)
// bool has_duplicates_slow(int *a, size_t n) 
// {
//     for (each element a[i]) {
//         for (each element a[j] from i+1 to the end) {
//             if (a[i] == a[j]) {
//                 return true
//             }
//         }
//     }
//     return false
// }

bool has_duplicates_slow(int *a, size_t n) 
{
    for (int i = 0;  i < n;  i++) {
        for (int j = i+1;  j < n;  j++) {
            if (a[i] == a[j]) {
                return true;
            }
        }
    }
    return false;
}

// O(n)
// bool has_duplicates01(int *a, size_t n)
// {
//     allocate "seen" table
//     for (each element a[i]) {
//         if (a[i] already marked as seen in table) {
//             free seen table
//             return true
//         }
//         put mark in table
//     }
//     free seen table
//     return false
// }

bool has_duplicates_fast(int *a, size_t n) {
    bool *seen = calloc(n*n, sizeof(bool));
    // bool *seen = malloc(n*n * sizeof(bool));
    for (int i = 0;  i < n;  i++) {
        if (seen[a[i]] == true) {
            free(seen);
            return true;
        }
        seen[a[i]] = true;
    }
    free(seen);
    return false;
}
