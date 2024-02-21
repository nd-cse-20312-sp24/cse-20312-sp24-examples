#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    int n = atoi(argv[1]);
    int array[n];
    int i;

    for (i = 0;  i < n;  i++) {
        array[i] = i;
    }

    for (i = 0;  i < n;  i++) {
        printf("%d ", array[i]);
    }
    printf("\nsizeof(array): %ld\n", sizeof(array));
    printf("&i:          %p\n", &i);
    printf("&n:          %p\n", &n);
    printf("&array[n-1]: %p\n", &array[n-1]);
    printf("array:       %p\n", array);
}