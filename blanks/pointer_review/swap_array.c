#include <stdio.h>

void swap(int x[]) {
    int temp = x[0];
    x[0] = x[1];
    x[1] = temp;
}

int main() {
    int x[2] = {5, 10};
    printf("Before: x[0]: %d    x[1]: %d\n", x[0], x[1]);
    swap(x);
    printf("After:  x[0]: %d    x[1]: %d\n", x[0], x[1]);
}