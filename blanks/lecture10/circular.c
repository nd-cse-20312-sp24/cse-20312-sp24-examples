#include "circular.h"

#include <assert.h>

Node *node_create(int value, Node *next, Node *prev) {
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->next = next;
    n->prev = prev;
    return n;
}

void node_delete(Node *n) { free(n); }

Circular *circular_create() { 
    
}

void circular_push_front(Circular *list, int value) {
    if (list->head == NULL) {
        
    } else {
        
    }
    // Don't forget to increment size
}

bool circular_empty(Circular *list) {
    return true;
}

void circular_insert_after(Circular *list, Node *node, int value) {
    // Don't forget to increment size
}

void circular_insert_before(Circular *list, Node *node, int value) {
    
}

void circular_push_back(Circular *list, int value) {
    
}

Node *circular_find(Circular *list, int value) {
    return NULL;
}

bool circular_contains(Circular *list, int value) {
    return NULL;
}

void circular_remove(Circular *list, Node *node) {
    assert(list->head);
    if (list->size == 1) {
        
    }



    if (node == list->head) {
        
    }

    // cleanup, don't forget to decrement size
}

int  circular_pop_front(Circular *list) {
    return 0;
}

int  circular_pop_back(Circular *list) {
    return 0;
}

void circular_delete(Circular *list) {
    
}
