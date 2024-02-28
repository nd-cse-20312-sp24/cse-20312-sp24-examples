/* map.c: Map Structure */

#include "map.h"

#include <stdio.h>
#include <string.h>

#include "hash.h"

/* Functions */

Map *map_create() {
    Map *m = calloc(1, sizeof(Map));
    m->capacity = MAP_DEFAULT_CAPACITY;
    m->buckets = calloc(m->capacity, sizeof(Pair *));
    return m;
}

void map_delete(Map *m) {
    for (int bucket = 0; bucket < m->capacity; bucket++) {
        pair_delete(m->buckets[bucket]);
    }

    free(m->buckets);
    free(m);
}

void map_insert(Map *m, char *key, int value) {
    int bucket = hash(key, strlen(key)) % m->capacity;

    if (map_lookup(m, key) >= 0) {
        return;
    }

    m->buckets[bucket] = pair_create(key, value, m->buckets[bucket]);
    m->size++;
}

int map_lookup(Map *m, char *key) {
    int bucket = hash(key, strlen(key)) % m->capacity;

    for (Pair *curr = m->buckets[bucket]; curr; curr = curr->next)
        if (strcmp(curr->key, key) == 0) return curr->value;

    return -1;
}

void map_format(Map *m) {
    for (int bucket = 0; bucket < m->capacity; bucket++) {
        printf("Bucket %d: ", bucket);
        for (Pair *curr = m->buckets[bucket]; curr; curr = curr->next)
            printf(" {%s: %d}", curr->key, curr->value);
        printf("\n");
    }
}
