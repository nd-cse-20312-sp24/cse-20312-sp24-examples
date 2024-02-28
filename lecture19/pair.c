/* pair.c: Pair Structure */

#include "pair.h"

#include <stdlib.h>
#include <string.h>

/* Functions */

Pair *pair_create(const char *key, int value, Pair *next) {
    Pair *p = calloc(1, sizeof(Pair));
    p->key = strdup(key);
    p->value = value;
    p->next = next;
    return p;
}

void pair_delete(Pair *p) {
    if (!p) return;

    pair_delete(p->next);
    free(p->key);
    free(p);
}
