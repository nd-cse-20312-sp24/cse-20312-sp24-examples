/* map_test.c: Map Test */

#include "map.h"
#include <stdio.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    Map *m = map_create();

    map_insert(m, "taylor", 9);
    map_insert(m, "olivia", 3);
    map_insert(m, "chief" , 4);
    map_insert(m, "justin", 1);

    map_format(m);

    printf("map_lookup(%s) = %d\n", "taylor", map_lookup(m, "taylor"));
    printf("map_lookup(%s) = %d\n", "olivia", map_lookup(m, "olivia"));
    printf("map_lookup(%s) = %d\n", "chief" , map_lookup(m, "chief"));
    printf("map_lookup(%s) = %d\n", "justin", map_lookup(m, "justin"));

    printf("map_lookup(%s) = %d\n", "knute", map_lookup(m, "knute"));

    map_delete(m);
    return 0;
}
