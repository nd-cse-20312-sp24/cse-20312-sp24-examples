/* addresses.c */

#include <stdio.h>
#include <stdlib.h>
    
char c = 'p';

int main(int argc, char *argv[]) {
    static float  f = 3.14;
    int    i = 321;
    double d = 3.14;

    printf("Value of c = %8c, Address of p = 0x%lx, Size of c = %lu\n", c, (unsigned long)&c, sizeof(c));
    printf("Value of f = %8f, Address of f = 0x%lx, Size of f = %lu\n", f, (unsigned long)&f, sizeof(f));
    printf("Value of i = %8d, Address of i = 0x%lx, Size of i = %lu\n", i, (unsigned long)&i, sizeof(i));
    printf("Value of d = %8lf, Address of d = 0x%lx, Size of d = %lu\n", d, (unsigned long)&d, sizeof(d));

    return EXIT_SUCCESS;
}
