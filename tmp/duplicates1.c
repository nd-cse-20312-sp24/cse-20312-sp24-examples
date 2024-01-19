// TODO: includes
#include <stdbool.h>
#include <stdio.h>

#include "library.h"

#define SIZE 4

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

bool has_duplicates(int *array, size_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                return true;
            }
        }
    }
    return false;
}

// int main()
// {
//     generate array of random numbers
//     has_duplicates(array, n)
//     print result string
// }

int main() {
    int array[SIZE];
    make_random_array(array, SIZE);
    bool result = has_duplicates(array, SIZE);
    puts(result ? "Yeah" : "Nope");
    return 1;
}