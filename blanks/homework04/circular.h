#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
    int value;
    Node *next;
    Node *prev;
};

Node *node_create(int value, Node *next, Node *prev);
void node_delete(Node *n);


typedef struct Circular Circular;
struct Circular {
    Node *head;
    int size;
};

Circular *circular_create();
void circular_push_front(Circular *list, int value);
bool circular_empty(Circular *list);
void circular_insert_after(Circular *list, Node *node, int value);
void circular_insert_before(Circular *list, Node *node, int value);
void circular_push_back(Circular *list, int value);
Node *circular_find(Circular *list, int value);
bool circular_contains(Circular *list, int value);
void circular_remove(Circular *list, Node *node);
int  circular_pop_front(Circular *list);
int  circular_pop_back(Circular *list);
void circular_delete(Circular *list);