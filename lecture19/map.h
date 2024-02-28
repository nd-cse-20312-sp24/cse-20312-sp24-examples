/* map.h: Map Structure */

#pragma once

#include <stdlib.h>

#include "pair.h"

/* Constants */

#define MAP_DEFAULT_CAPACITY (1 << 2)

/* Structure */

typedef struct {
    Pair **buckets;
    int capacity;
    int size;
} Map;

/* Functions */

Map *map_create();
void map_delete(Map *m);

void map_insert(Map *m, char *key, int value);
int map_lookup(Map *m, char *key);

void map_format(Map *m);
