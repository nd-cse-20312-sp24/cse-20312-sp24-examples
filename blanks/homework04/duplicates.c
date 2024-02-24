#include "circular.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define LINE_SIZE 1024

// Find duplicate values in a string of characters that
// represent numbers delimited by a space character.

// Traverse the string and print a number if there exists
// the same number earlier in the string.

// Print your results as a single line of integer values, separated by a
// space and terminated with a newline.  If there are no duplicates, print
// a newline only.
void find_duplicates(char *s) {
    // Use a Circular as a set to keep track of numbers
    // previously encountered.  Use strtok to parse the string
    // and either atoi or sscanf to convert the string representation
    // of numbers to integers
}

int main() {
    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, stdin)) {
        find_duplicates(line);
    }
    return 0;
}