#include <stdio.h>
#include <stdlib.h>

void fib(int *a, int n) {
    a[0] = 0;
    a[1] = 1;
    
    for (int i = 2;  i < n;  i++) {
        a[i] = a[i-1] + a[i-2];
    }
}


int main() {
    int length = 10;
    int *array = malloc(length * sizeof(int));
    fib(array, length);
    printf("%d\n", array[length-1]);
    printf("hello\n");
}