#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void array_of_strings_print_index(char **aos) {
    // TODO
    for (int i = 0;  aos[i] != 0;  i++) {
        puts(aos[i]);
    }
}

void array_of_strings_print_ptr(char **aos) {
    // TODO
    for (char **p = aos;  *p != 0;  p++) {
        puts(*p);
    }
}

int main( ) {
    // TODO
    char *str0 = strdup("ab");
    char **array_of_strings = calloc(4, sizeof(char*));
    array_of_strings[0] = str0;
    array_of_strings[1] = strdup("cde");
    array_of_strings[2] = strdup("fg");

    puts("---------- print using index notations");
    array_of_strings_print_index(array_of_strings);
    puts("---------- print using pointer notations");
    array_of_strings_print_ptr(array_of_strings);
    return 0;
}
