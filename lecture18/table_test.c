#include "table.h"
#include <stdio.h>

/* Constants */

const int DATA[] =    {25, 12, 14, 15, 17, -1};
// const int DATA[] =    {25, 17, 33, 41, 49, 57, 65, 73, 81, -1};

/* Main Execution */

int main(int argc, char *argv[]) {
    Table *t = table_create();

    puts("Print hash value and (hash value) mod (capacity)");
    for (const int *p = DATA; *p >= 0; p++) {
    	printf("hash(%d) = %u, %d\n", *p, hash(*p), hash(*p) % t->capacity);
    }

    // Insert the DATA into the hash table
    for (const int *p = DATA; *p >= 0; p++) {
    	table_insert(t, *p);
    }

    puts("");
    puts("Print the table contents");
    table_format(t);

    puts("");
    puts("See if each of the DATA values is found in the table");
    for (const int *p = DATA; *p >= 0; p++) {
    	printf("table_search(%d) ? %d\n", *p, table_search(t, *p));
    }

    table_delete(t);
    return 0;
}
