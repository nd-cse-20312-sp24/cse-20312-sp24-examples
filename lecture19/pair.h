/* pair.h: Pair Structure */

#pragma once

/* Structure */

typedef struct Pair Pair;
struct Pair {
    char *key;
    int   value;
    Pair *next;
};

/* Functions */

Pair *	pair_create(const char *key, int value, Pair *next);
void	pair_delete(Pair *p);
