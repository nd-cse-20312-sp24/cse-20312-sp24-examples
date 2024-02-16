#include "search.h"
#include <stdio.h>

int main() {
    Array *array = array_create();
    for (int i = 0;  i < 16;  i++) {
        array_append(array, i);
    }

    if (binary_search_r(array, 4, 0, array->size - 1)) {
        puts("found");
    } else {
        puts("not found");
    }
}