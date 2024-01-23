/* stack.c */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int power(int base, int exponent) {
    if (exponent <= 1)
    	return 1;

    return base * power(base, exponent - 1);
}

int twice(int x) {
    int result = x + x;
    return result;
}

int undefined(int x) {
    int value;
    printf("value is: %d\n", value);
    return value;
}

int main(int argc, char *argv[]) {
    /* INT_MAX is way too big.  Use `ulimit -a` to see stack size and then do
     * something like int a[(limit - 16)*1024/4];
     */
    // int a[INT_MAX];
    // int a[1 << 20];  // this is the maximum that works on WSL

    /* This causes a stack overflow because we recurse too much and thus blow
     * up the stack with activation records. */
    power(2, 1<<20);
    //power(2, 1<<20);

    /* Memory allocation is automatic on the stack
     * Using gdb:
     *	- info f	(frame information)
     *	- info args	(arguments to function)
     *	- info locals	(local variables)
     */
    twice(1);
    undefined(0);

    /* Memory is not cleared when deallocated, so we can pickup previous values */

    twice(4);
    undefined(0);
    return EXIT_SUCCESS;
}
