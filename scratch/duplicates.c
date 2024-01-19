#include <stdbool.h>
#include <stdlib.h>

#include "duplicates.h"

bool has_duplicates00(int *a, size_t n) 
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

bool has_duplicates01(int *a, size_t n)
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
