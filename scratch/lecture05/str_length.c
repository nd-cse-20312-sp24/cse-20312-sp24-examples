/* str_length.c */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t str_length(const char *s) {
    const char *c;
    for (c = s; *c; c++);
    return (c - s);
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
    	assert(str_length(argv[i]) == strlen(argv[i]));
    	printf("%lu: %s\n", str_length(argv[i]), argv[i]);
    }

    char buffer[BUFSIZ]; // BAD: char *buffer = "";
    while (fgets(buffer, BUFSIZ, stdin)) {
    	assert(str_length(buffer) == strlen(buffer));
    	printf("%lu: %s", str_length(buffer), buffer);
    }

    return EXIT_SUCCESS;
}
