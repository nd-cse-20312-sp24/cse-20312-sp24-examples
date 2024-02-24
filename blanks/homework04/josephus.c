#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "circular.h"

#define LINE_SIZE 1024

// Given a Circular, repeatedly remove every kth Node
// in the forward direction, until only one Node remains
// Print the value of each Node as it is removed, followed by
// the value of the last Node on a single line terminated by a
// newline, delimited by a space.
void josephus_forward(Circular *circle, int k) {
}

// Given a Circular, repeatedly remove every kth Node
// in the reverse direction, until only one Node remains
// Print the value of each Node as it is removed, followed by
// the value of the last Node on a single line terminated by a 
// newline, delimited by a space.
void josephus_reverse(Circular *circle, int k) {
}

int main() {
    char line[LINE_SIZE];
    int n;
    int k;
    char dir[2];
    while (fgets(line, LINE_SIZE, stdin)) {
        sscanf(line, "%d %d %s", &n, &k, dir);
        Circular *circle = circular_create();
        for (int i = 1; i <= n; i++) {
            circular_push_back(circle, i);
        }
        if (!strcmp(dir, "f")) {
            josephus_forward(circle, k);
        } else if (!strcmp(dir, "r")) {
            josephus_reverse(circle, k);
        } else {
            puts("unknown direction");
            return EXIT_FAILURE;
        }
        circular_delete(circle);
    }
    return EXIT_SUCCESS;
}
