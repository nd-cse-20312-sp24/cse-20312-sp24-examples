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

    printf("   a. Address: 0x%012lx, Size: %lu\n", (uintptr_t) &a, sizeof( a));
    puts("");
    printf("   s. Address: 0x%012lx, Size: %lu\n", (uintptr_t)  s, sizeof( s));
    printf("  &s. Address: 0x%012lx, Size: %lu\n", (uintptr_t) &s, sizeof(&s));
    printf("  *s. Address: 0x%012lx, Size: %lu\n", (uintptr_t)&*s, sizeof(*s));
    puts("");
    printf("  p0. Address: 0x%012lx, Size: %lu\n", (uintptr_t) p0, sizeof( p0));
    printf(" &p0. Address: 0x%012lx, Size: %lu\n", (uintptr_t)&p0, sizeof(&p0));
    printf("  p1. Address: 0x%012lx, Size: %lu\n", (uintptr_t) p1, sizeof( p1));
    printf(" &p1. Address: 0x%012lx, Size: %lu\n", (uintptr_t)&p1, sizeof(&p1));
    printf("  p2. Address: 0x%012lx, Size: %lu\n", (uintptr_t) p2, sizeof( p2));
    printf(" &p2. Address: 0x%012lx, Size: %lu\n", (uintptr_t)&p2, sizeof(&p2));
    puts("");
    printf("  GD. Address: 0x%012lx, Size: %lu\n", (uintptr_t)&GD, sizeof(GD));
    printf("   t. Address: 0x%012lx, Size: %lu\n", (uintptr_t) &t, sizeof(t));
    puts("");
    printf("main. Address: 0x%012lx, Size: %lu\n", (uintptr_t)&main, sizeof(main));

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
