#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;
    printf("Before: x: %d    y: %d\n", x, y);
    swap(&x, &y);
    printf("After: x: %d    y: %d\n", x, y);
}