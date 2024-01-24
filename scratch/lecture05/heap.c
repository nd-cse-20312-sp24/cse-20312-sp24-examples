/* heap.c */

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int *h = malloc(INT_MAX*sizeof(int));

    // Doesn't fail on Linux
    if (!h) {
    	fprintf(stderr, "malloc failed: %s\n", strerror(errno));
    	return EXIT_FAILURE;
    }

    // Show ps ux: virtual vs physical memory
    sleep(10);

    // Force physical allocation
    puts("away we go...");
    for (int i = 0; i < INT_MAX; i++) {
    	h[i] = i;
    	if (i % 10000 == 0) {
    	    usleep(1);
	}
    }
    return EXIT_SUCCESS;
}
