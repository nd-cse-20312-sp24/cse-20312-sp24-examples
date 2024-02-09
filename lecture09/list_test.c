/* Lecture 09: Linked List */

#include "list.h"

#include <stdio.h>
#include <stdlib.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    List l = {0};

    list_push(&l, 5);
    list_push(&l, 7);
    list_push(&l, 4);

    printf("list_at(%d) = %d\n", 0, list_at(&l, 0));
    printf("list_at(%d) = %d\n", 1, list_at(&l, 1));
    printf("list_at(%d) = %d\n", 2, list_at(&l, 2));
    printf("list_at(%d) = %d\n", 9, list_at(&l, 9));

    printf("list_index(%d) = %d\n", 5, list_index(&l, 5));
    printf("list_index(%d) = %d\n", 7, list_index(&l, 7));
    printf("list_index(%d) = %d\n", 4, list_index(&l, 4));
    printf("list_index(%d) = %d\n", 9, list_index(&l, 9));

    while (l.head) {
    	printf("list_pop() = %d\n", list_pop(&l));
    }

    node_delete(l.head);
    return 0;
}
