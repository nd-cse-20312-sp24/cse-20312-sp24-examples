#include "string_methods.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return the size of the array of strings (ie. number of strings).
 *
 *  strings_size({"a", "b", "c", NULL}) -> 3
 *
 * @param   sv	    Array of strings (terminated by NULL pointer)
 * @return  Size of the array of strings
 **/
size_t string_array_size(char **sv) {
    // TODO: Count the number of strings in array and return the count

    return 0;
}

/**
 * Return true if the array of strings contains a given string
 * *
 * @param   sv	    Array of strings (terminated by NULL pointer)
 * @param   s	    String
 * @return  True if array contains string
 **/
bool string_array_contains(char **sv, char *s) {
    // TODO: Traverse the array to see if one of the strings
    // is a match.  Hint: use strcmp

    return false;
}

/**
 * Release all the words in array of strings and the array itself.
 *
 * @param   sv	    Array of strings (terminated by NULL pointer)
 **/
void string_array_free(char **sv) {
    // TODO: Free each string in the array and then the array itself

}

/**
 * Remove trailing newline from string (if it exists).
 *
 *  string_chomp("abc\n") -> "abc"
 *
 * @param   s	    String to chomp
 **/
void string_chomp(char *s) {
    // TODO: Remove trailing newline from string if it exists

}

/**
 * Split string by delimiter character into a new array of strings.
 *
 *  string_split("a,b,c", ',') -> {"a", "b", c", NULL}
 *
 * Note: the array of strings is terminated by a NULL pointer.
 *
 * @param   s	    String to split
 * @param   delim   Delimiter to split string by
 * @return  New array of strings (must be freed later)
 **/
char **string_split(char *s, char delim) {
    // TODO: Allocate an array for up to 99 strings, terminated by a
    // NULL pointer.

    // TODO: Scan string and copy words separated by delimiter 
    // to array of strings.  Hint: Use strndup to allocate memory and
    // make a copy of individual words.

    return NULL;
}

/**
 * Return a string array of strings that are duplicated in 2 string arrays
 *
 * @param   sv1	    Array of strings (terminated by NULL pointer)
 * @param   sv2	    Array of strings (terminated by NULL pointer)
 * @return  Array of strings (terminated by NULL pointer)
 **/
char **string_find_dups(char **sv1, char **sv2) {
    // TODO: Allocate an array for up to 99 strings, terminated by a
    // NULL pointer.
    
    // TODO: Look for strings that are in both sv1 and sv2 and add
    // them to the output list as you find them.

    return NULL;
}



