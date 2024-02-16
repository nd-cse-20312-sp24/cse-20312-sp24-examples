/* Lecture 12: Search algorithms */

#pragma once

#include "array.h"

#include <stdbool.h>
#include <stdlib.h>

/* Functions */

bool binary_search(Array *array, int target);
bool binary_search_r(Array *array, int target, int start, int end);

bool linear_search(Array *array, int target);
bool linear_search_r(Array *array, int target, int index);
