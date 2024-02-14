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
    Circular *list = malloc(sizeof(Circular)); 
    list->head = NULL;
    list->size = 0;
    return list;
}

void circular_push_front(Circular *list, int value) {
    if (list->head == NULL) {
        Node *n = node_create(value, NULL, NULL);
        n->next = n;
        n->prev = n;
        list->head = n;
    } else {
        Node *n = node_create(value, list->head, list->head->prev);
        list->head->prev->next = n;
        list->head->prev = n;
        list->head = n;
    }
    list->size++;
}

bool circular_empty(Circular *list) {
    return true;
}

void circular_insert_after(Circular *list, Node *node, int value) {
    assert(list->head);
    Node *n = node_create(value, node->next, node);
    node->next->prev = n;
    node->next = n;
    list->size++;
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
        node_delete(list->head);
        list->head = NULL;
        list->size = 0;
        return;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;

    if (node == list->head) {
        list->head = list->head->next;
    }

    node_delete(node);
    list->size--;
}

int  circular_pop_front(Circular *list) {
    return 0;
}

int  circular_pop_back(Circular *list) {
    return 0;
}

void circular_delete(Circular *list) {
    while (list->size > 0) {
        circular_remove(list, list->head);
    }
    free(list);
}
