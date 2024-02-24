#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_methods.h"

int status = EXIT_FAILURE;

char* class1[] = {"ab", "bc", "cd", "de", NULL};
char* class2[] = {"de", "xx", "yy", "ab", "bc", NULL};

int test_0_string_array_size() {
    assert(string_array_size(class1) == 4);
    assert(string_array_size(class2) == 5);
    return EXIT_SUCCESS;
}

int test_1_string_array_contains() {
    assert(string_array_contains(class1, "ab") == true);
    assert(string_array_contains(class1, "de") == true);
    assert(string_array_contains(class1, "xx") == false);
    return EXIT_SUCCESS;
}

int test_2_string_array_free() {
    // This exercises the function but doesn't test if
    // memory has been freed.  Use valgrind to
    // check for memory leaks
    char **sa = malloc(3 * sizeof(char *));
    sa[0] = strdup("hello");
    sa[1] = strdup("goodbye");
    sa[2] = NULL;
    string_array_free(sa);
    return EXIT_SUCCESS;
}

int test_3_string_chomp() {
    char   s1[]  = "later,alligator\n";
    size_t size1 = strlen(s1);
    string_chomp(s1);
    assert(strlen(s1) == size1 - 1);
    assert(*(s1 + size1 - 1) == 0);
    
    char   s2[]  = "later,alligator";
    size_t size2 = strlen(s1);
    string_chomp(s2);
    assert(strlen(s2) == size2);
    assert(*(s1 + size2) == 0);
    return EXIT_SUCCESS;
}

int test_4_string_split() {
    char s1[] = "abc,de,fghi";
    char **sarray = string_split(s1, ',');
    assert(strcmp(sarray[0], "abc") == 0);
    assert(strcmp(sarray[1], "de") == 0);
    assert(strcmp(sarray[2], "fghi") == 0);
    string_array_free(sarray);
    return EXIT_SUCCESS;
}

int test_5_string_find_dups() {
    char** dups = string_find_dups(class1, class2);
    assert(string_array_contains(dups, "ab") == true);
    assert(string_array_contains(dups, "bc") == true);
    assert(string_array_contains(dups, "de") == true);
    assert(string_array_contains(dups, "xx") == false);
    assert(string_array_size(dups) == 3);
    string_array_free(dups);
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
        fprintf(stderr, "Where NUMBER is one of the following:\n");
        fprintf(stderr, "    0  Test string_array_size\n");
        fprintf(stderr, "    1  Test string_array_contains\n");
        fprintf(stderr, "    2  Test string_array_free\n");
        fprintf(stderr, "    3  Test string_chomp\n");
        fprintf(stderr, "    4  Test string_split\n");
        fprintf(stderr, "    5  Test string_find_dups\n");
        return EXIT_FAILURE;
    }

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
        case 0:  status = test_0_string_array_size(); break;
        case 1:  status = test_1_string_array_contains(); break;
        case 2:  status = test_2_string_array_free(); break;
        case 3:  status = test_3_string_chomp(); break;
        case 4:  status = test_4_string_split(); break;
        case 5:  status = test_5_string_find_dups(); break;
       default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }

    return status;
}