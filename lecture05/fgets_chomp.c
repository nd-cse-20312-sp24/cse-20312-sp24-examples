#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    puts("Enter a string:");
    fgets(buffer, 100, stdin);
    puts(buffer);
    printf("string length = %ld\n", strlen(buffer));
    // chomp off the newline
    buffer[strlen(buffer) - 1] = 0;
    puts(buffer);
    printf("string length = %ld\n", strlen(buffer));
}