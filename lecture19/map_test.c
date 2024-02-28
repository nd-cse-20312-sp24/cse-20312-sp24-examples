/* map_test.c: Map Test */

#include "map.h"

#include <stdio.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    Map *m = map_create();

    map_insert(m, "apple", 9);
    map_insert(m, "orange", 3);
    map_insert(m, "banana" , 4);
    map_insert(m, "grape", 1);

    map_format(m);

    printf("map_lookup(%s) = %d\n", "apple", map_lookup(m, "apple"));
    printf("map_lookup(%s) = %d\n", "orange", map_lookup(m, "orange"));
    printf("map_lookup(%s) = %d\n", "banana" , map_lookup(m, "banana"));
    printf("map_lookup(%s) = %d\n", "grape", map_lookup(m, "grape"));

    printf("map_lookup(%s) = %d\n", "peach", map_lookup(m, "peach"));

    map_delete(m);
    return 0;
}
