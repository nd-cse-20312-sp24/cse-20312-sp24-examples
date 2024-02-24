#include <stdio.h>
#include <stdlib.h>

int main() {
    int local_array[4];
    local_array[0] = 100;
    local_array[1] = 101;
    *(local_array + 2) = 102;
    *(local_array + 3) = 103;

    int *heap_array = malloc(4 * sizeof(int));
    heap_array[0] = 200;
    heap_array[1] = 201;
    *(heap_array + 2) = 202;
    *(heap_array + 3) = 203;
}