#include <stdio.h>

int main() {
    char *p = "pointer";
    char a[] = "array";

    printf("sizeof(p): %ld\n", sizeof(p));
    printf("sizeof(a): %ld\n", sizeof(a));

    puts(p);
    puts(a);
    a[0] = 'X';
    puts(a);
    
    // Can you write a value to a string constant?
    // p[0] = 'X';
    // puts(p);
    
    // Can you assign a new address value to a char* variable?
    // p = a;
    // puts(p);

    // Can you assign a new address value to an array label?
    // a = p;
    // puts(a);
}