/* hash.c: Hash Function */

#include "hash.h"

#include <stdint.h>

/* Functions */

int	hash(char *s, int n) {
    // Very bad and dumb hash: add up characters and then use Knuth's
    // multiplicative hash
    
    int value = 0;

    for (int c = 0; c < n; c++) {
    	value += s[c];
    }

    return value;
}
