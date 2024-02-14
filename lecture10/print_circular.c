#include "circular.h"
#include <stdio.h>

int main() {
    Circular *list = circular_create();
    circular_push_front(list, 3);
    circular_push_front(list, 2);
    circular_push_front(list, 1);

    Node *curr = list->head;
    do {
        printf("%d\n", curr->value);
        curr = curr->next;
    } while(curr != list->head);
}