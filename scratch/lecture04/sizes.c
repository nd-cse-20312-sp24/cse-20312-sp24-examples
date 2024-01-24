/* sizes.c: sizes of common types */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    printf("sizeof(bool)   = %lu\n", sizeof(bool));
    printf("sizeof(char)   = %lu\n", sizeof(char));
    printf("sizeof(int)    = %lu\n", sizeof(int));
    printf("sizeof(float)  = %lu\n", sizeof(float));
    printf("sizeof(double) = %lu\n", sizeof(double));
    puts("");
    printf("sizeof(signed)        = %lu\n", sizeof(signed));
    printf("sizeof(unsigned)      = %lu\n", sizeof(unsigned));
    printf("sizeof(short)         = %lu\n", sizeof(short));
    printf("sizeof(long)          = %lu\n", sizeof(long));
    printf("sizeof(long unsigned) = %lu\n", sizeof(long unsigned));
    puts("");
    printf("sizeof(int8_t)        = %lu\n", sizeof(int8_t));
    printf("sizeof(uint8_t)       = %lu\n", sizeof(uint8_t));
    printf("sizeof(int32_t)       = %lu\n", sizeof(int32_t));
    printf("sizeof(uint64_t)      = %lu\n", sizeof(uint64_t));
    return 0;
}
