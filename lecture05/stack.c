/* stack.c */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int twice(int x) {
    int result = x + x;
    printf("twice:\t  &result = %p   result = %d\n", &result, result);
    return result;
}

int func(int x) {
    int result = twice(x) + 7;
    printf("func:\t  &result = %p   result = %d\n", &result, result);
    return result;
}

int undef(int x) {
    int result;
    printf("undef:\t  &result = %p   result = %d\n", &result, result);
    return result;
}

int main() {
    func(4);

    /* Memory is not cleared when deallocated, so we can pickup previous values */
    // TODO: comment undef in and out before and after call to func
    // undef(0);

    return EXIT_SUCCESS;
}
