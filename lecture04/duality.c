/* duality.c */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void dump(int *a, int n) {
    // WRONG: n = sizeof(a) / sizeof(int);
    printf("[] notation\n");
    for (size_t i = 0; i < n; i++) {
    	printf("%ld. %d\n", i, a[i]);
    }
    
    // POINTERS: only
    printf("pointer notation\n");
    for (int *p = a; p < (a + n); p++) {
    	printf("%ld. %d\n", p - a, *p);
    }

    // SENTINEL: 
    printf("sentinel\n");
    for (int *p = a; *p >= 0; p++) {
        printf("%ld. %d\n", p - a, *p);
    }

}

int main(int argc, char *argv[]) {
    int a[]  = {5, 4, 7, 0, 1, -1};
    size_t n = sizeof(a) / sizeof(int);

    for (size_t i = 0; i < n; i++) {
    	assert(a[i]  == *(a + i));
    	assert(a[i]  == *(i + a));
    	assert(a[i]  == i[a]);
	    assert(a + i == &a[i]);
    }

    dump(a, n);
    return EXIT_SUCCESS;
}
