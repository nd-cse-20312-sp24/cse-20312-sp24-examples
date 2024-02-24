#pragma once

#include "array.h"

/* Structures */

typedef Array Set;

/* Functions */

Set* set_create();
void set_delete(Set *set);
void set_add(Set *set, int value);
bool set_contains(Set *set, int value);
void set_remove(Set *set, int value);
