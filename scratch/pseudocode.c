#include <stdlib.h>
#include <stdbool.h>

// basic time O(n^2) solution
// bool has_duplicates_slow(a, n)
// {
//     for (each element a[i]) {
//         for (each element a[j] from i+1 to end of array) {
//             if (array[i] == a[j]) {
//                 return true
//             }
//         }
//     }
//     return false
// }

bool has_duplicates_slow(int *a, size_t n) 
{
    for (size_t i = 0;  i < n;  i++) {
        for (size_t j = i + 1;  j < n;  j++) {
            if (a[i] == a[j]) {
                return true;
            }
        }
    }
    return false;
}

// O(n) time, O(n^2) space using "seen" table
// bool has_duplicates_fast(a, n)
// {
//     allocate "seen" table
//     for (each element in a) {
//         if (it has already been seen in table) {
//             // deallocate seen table
//             return true
//         }
//     }
//     // deallocate seen table
//     return false
// }

bool has_duplicates_fast(int *a, size_t n)
{
    bool *seen = calloc(n*n, sizeof(bool));
    for (size_t i = 0;  i < n;  i++) {
        if (seen[a[i]] == true) {
            free(seen);
            return true;
        }
        seen[a[i]] = true;
    }
    free(seen);
    return(false);
}