/* pointers.c */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
    int  x = 1;
    int  y = 2;
    int *p = NULL;


    printf("x = %16d, Address of x = 0x%lx, Size of x = %lu\n", x, (intptr_t)&x, sizeof(x));
    printf("y = %16d, Address of y = 0x%lx, Size of y = %lu\n", y, (intptr_t)&y, sizeof(y));
    printf("p = %16lx, Address of p = 0x%lx, Size of p = %lu\n\n", (intptr_t)p, (intptr_t)&p, sizeof(p));
    // printf("*p == x ? %d\n", *p == x);
    // printf("*p == y ? %d\n\n", *p == y);

    puts("p = &x");
    p = &x;
    printf("x = %16d, Address of x = 0x%lx\n", x, (intptr_t)&x);
    printf("y = %16d, Address of y = 0x%lx\n", y, (intptr_t)&y);
    printf("p = %16lx, Address of p = 0x%lx\n", (intptr_t)p, (intptr_t)&p);
    printf("*p == x ? %d\n", *p == x);
    printf("*p == y ? %d\n\n", *p == y);

    puts("p--");
    p--;
    printf("x = %16d, Address of x = 0x%lx\n", x, (intptr_t)&x);
    printf("y = %16d, Address of y = 0x%lx\n", y, (intptr_t)&y);
    printf("p = %16lx, Address of p = 0x%lx\n", (intptr_t)p, (intptr_t)&p);
    printf("*p == x ? %d\n", *p == x);
    printf("*p == y ? %d\n\n", *p == y);

    puts("p++");
    p++;
    printf("x = %16d, Address of x = 0x%lx\n", x, (intptr_t)&x);
    printf("y = %16d, Address of y = 0x%lx\n", y, (intptr_t)&y);
    printf("p = %16lx, Address of p = 0x%lx\n", (intptr_t)p, (intptr_t)&p);
    printf("*p == x ? %d\n", *p == x);
    printf("*p == y ? %d\n\n", *p == y);

    puts("p = &y");
    p = &y;
    printf("x = %16d, Address of x = 0x%lx\n", x, (intptr_t)&x);
    printf("y = %16d, Address of y = 0x%lx\n", y, (intptr_t)&y);
    printf("p = %16lx, Address of p = 0x%lx\n", (intptr_t)p, (intptr_t)&p);
    printf("*p == x ? %d\n", *p == x);
    printf("*p == y ? %d\n\n", *p == y);

    return EXIT_SUCCESS;
}
