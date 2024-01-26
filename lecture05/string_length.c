#include <stdio.h>

size_t string_length(char *s) {
    char *p;
    for(p = s;  *p;  p++) {}
    return p - s;
}

int main() {
    char *string = "12345";

    printf("length is %ld\n", string_length(string));
}