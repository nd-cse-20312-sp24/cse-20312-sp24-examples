/* table.c: Hash Table */
// Demonstrate a hash table for data values of (non-zero) positive integers
// We will look at a hash table for strings later!

#include "table.h"
#include <stdio.h>

/* Functions */

Table *table_create() {
    Table *t = calloc(1, sizeof(Table));
    if (t) {
        t->capacity = TABLE_DEFAULT_CAPACITY;
        t->buckets = calloc(t->capacity, sizeof(int));
    }
    return t;
}

void table_delete(Table *t) {
    free(t->buckets);
    free(t);
}

uint32_t hash(int value) {
    // Knuth Multiplicative Hash
    return value * 2654435761;
}

void table_insert(Table *t, int value) {
    // No collision handling
    // int bucket = hash(value) % t->capacity;
    // t->buckets[bucket] = value;

    // Linear probing
    int bucket = table_locate(t, value);
    t->buckets[bucket] = value;

    t->size++;
}

bool table_search(Table *t, int value) {
    // No collision handling
    // int bucket = hash(value) % t->capacity;
    // return t->buckets[bucket] == value;

    // Linear probing
    int bucket = table_locate(t, value);
    // return (bucket >= 0) && 
    //        (t->buckets[bucket] == value);
    return (bucket >= 0);
}

void table_format(Table *t) {
    for (int bucket = 0; bucket < t->capacity; bucket++) {
        printf("buckets[%d]: %d\n", bucket, t->buckets[bucket]);
    }
}

int table_locate(Table *t, int value) {
    int bucket = hash(value) % t->capacity;
    int probe = 0;

    // Stop when:
    //	1. Run out of probes
    //	2. Find empty
    //	3. Find match
    while (probe < t->capacity && 
           t->buckets[bucket] != 0 &&
           t->buckets[bucket] != value) {
        bucket = (bucket + 1) % t->capacity;
        probe++;
    }

    // return (probe < t->capacity) ? bucket : -1;
    if (probe < t->capacity) {
        return bucket;
    } else {
        return -1;
    }
}
