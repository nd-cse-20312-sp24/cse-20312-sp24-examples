/* table.h: Hash Table */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

/* Constants */

// #define TABLE_DEFAULT_CAPACITY (1 << 2)
#define TABLE_DEFAULT_CAPACITY 8

/* Structures */

typedef struct {
    int *buckets;
    int capacity;
    int size;
} Table;

/* Functions */

Table *table_create();
void table_delete(Table *t);

uint32_t hash(int value);

void table_insert(Table *t, int value);
bool table_search(Table *t, int value);

void table_format(Table *t);
int table_locate(Table *t, int value);
