#pragma once

#include <stdlib.h>
#include <stdbool.h>

size_t string_array_size(char **sv);
bool string_array_contains(char **sv, char *s);
void string_array_free(char **sv);
void string_chomp(char *s);
char **string_split(char *s, char delim);
char **string_find_dups(char **class1, char **class2);
