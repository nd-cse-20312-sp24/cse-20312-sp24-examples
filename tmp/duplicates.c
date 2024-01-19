#include <stdbool.h>
#include <stdlib.h>

#include "duplicates.h"

// bool has_duplicates(array, n)
// {
//     for (i = each element in array) {
//         for (j = next element to last element) {
//             if (ith element == jth element) {
//                 return true;
//             }
//         }
//     }
//     return false
// }

bool has_duplicates0(int *array, size_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                return true;
            }
        }
    }
    return false;
}

bool has_duplicates1(int *array, size_t n) {
    // allocate a seen array initialized to zero
    // bool *seen = malloc(n*n * sizeof(bool));  // cause valgrind error
    bool *seen = calloc(n*n, sizeof(bool));
    // for each element in array {
    //     if element has been seen {
    //         return true
    //     }
    //     note element as seen
    // }
    for (int i = 0;  i < n;  i++) {
        if (seen[array[i]] == true) {
            free(seen);
            return true;
        }
        seen[array[i]] = true;
    }
    free(seen);
    return false;
}
