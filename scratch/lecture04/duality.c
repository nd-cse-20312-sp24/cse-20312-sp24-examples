/* duality.c */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void dump(int *a, int n) {
    printf("[] notation\n");
    
    
    // POINTERS: only
    printf("pointer notation\n");
    

    // SENTINEL: 
    printf("sentinel\n");
    

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