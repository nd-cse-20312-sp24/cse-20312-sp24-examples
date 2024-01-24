/* regions.c */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

double GD = 3.14;

int main(int argc, char *argv[]) {
    int        a[] = {4, 6, 6, 3, 7};
    char      *s   = "Globes and Maps";
    int      *p0   = NULL;
    int      *p1   = malloc(sizeof(int));
    int      *p2   = malloc(10*sizeof(int));
    static int t   = 2;

    puts("----------------stack----------------");
    printf("   a. Address: %12lx, Size: %lu\n", (uintptr_t) &a, sizeof( a));  // stack
    printf("  &s. Address: %12lx, Size: %lu\n", (uintptr_t) &s, sizeof(&s));  // stack
    printf(" &p0. Address: %12lx, Size: %lu\n", (uintptr_t)&p0, sizeof(&p0)); // stack
    printf(" &p1. Address: %12lx, Size: %lu\n", (uintptr_t)&p1, sizeof(&p1)); // stack
    printf(" &p2. Address: %12lx, Size: %lu\n", (uintptr_t)&p2, sizeof(&p2)); // stack
    puts("----------------heap----------------");
    printf("  p2. Address: %12lx, Size: %lu\n", (uintptr_t) p2, sizeof( p2)); // heap
    printf("  p1. Address: %12lx, Size: %lu\n", (uintptr_t) p1, sizeof( p1)); // heap
    puts("----------------data----------------");
    printf("   t. Address: %12lx, Size: %lu\n", (uintptr_t) &t, sizeof(t));   // data
    printf("  GD. Address: %12lx, Size: %lu\n", (uintptr_t)&GD, sizeof(GD));  // data
    printf("   s. Address: %12lx, Size: %lu\n", (uintptr_t)  s, sizeof( s));  // data
    printf("  *s. Address: %12lx, Size: %lu\n", (uintptr_t)&*s, sizeof(*s));  // data (same as s)
    puts("----------------code----------------");
    printf("main. Address: %12lx, Size: %lu\n", (uintptr_t)&main, sizeof(main));  // code
    puts("----------------0----------------");
    printf("  p0. Address: %12lx, Size: %lu\n", (uintptr_t) p0, sizeof( p0)); // 0

    /* Demonstrations
     *
     * - Segfault if we do `s[1] = 'b'`.  No segfault if we change *s to s[].
     *
     *	    Arrays are LIKE pointers, are not actually pointers (can't do
     *	    assignment, don't take up their own space).
     *
     * - Running repeatedly will show that the stack and heap allocations
     *   change, but not the code and data variables do not.
     */
    return EXIT_SUCCESS;
}
