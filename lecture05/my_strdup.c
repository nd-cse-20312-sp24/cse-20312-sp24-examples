#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strdup(char *str) {
    char *copy = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(copy, str);
    return copy;
}

int main() {
    char *s = NULL;

    s = my_strdup("ab");
    printf("s: %16p    string at s: %4s   length: %ld\n", s, s, strlen(s));

    s = strdup("cde");
    printf("s: %16p    string at s: %4s   length: %ld\n", s, s, strlen(s));
}