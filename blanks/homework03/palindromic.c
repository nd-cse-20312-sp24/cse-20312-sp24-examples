#include <stdio.h>
#include <string.h>

#include "set.h"

#define BUF_SIZE 1024

bool is_palindromic(char *s) {
    // Return true if string s is a palindromic permutation
    // Use a set as part of your solution
    // TODO:

}

int main() {
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, stdin)) {
        buffer[strlen(buffer) - 1] = 0;  // chomp the newline
        if (is_palindromic(buffer)) {
            puts("YEAH");
        } else {
            puts("NOPE");
        }
    }
    return EXIT_SUCCESS;
}