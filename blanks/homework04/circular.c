#include "circular.h"
#include <assert.h>

// Allocate a Node from the heap and initialize
// its next and prev attributes
Node *node_create(int value, Node *next, Node *prev) {
    return NULL;
}

// Free a Node
void node_delete(Node *n) { 
}

// Allocate a Circular from the heap and
// initialize its head and size attributes
Circular *circular_create() { 
    return NULL;
}

// Allocate a Node, initialize its value, push it
// at the head of a Circular and increment the size
void circular_push_front(Circular *list, int value) {
    // Be sure to consider separately the cases where the
    // Circular is empty and where it already has Nodes.
}

// Test if a Circular is empty
bool circular_empty(Circular *list) {
}

// Allocate a new Node with a given value and insert it after
// a specified node in a Circular
void circular_insert_after(Circular *list, Node *node, int value) {
    assert(list->head);
}

// Allocate a new Node with a given value and insert it before
// a specified node in a Circular
void circular_insert_before(Circular *list, Node *node, int value) {
    assert(list->head);
}

// Allocate a new Node with a given value and insert it at the
// tail of a Circular (before the head)
void circular_push_back(Circular *list, int value) {
    // Be sure to consider separately the cases where the
    // Circular is empty and where it already has Nodes.  You can
    // use functions you have already written to simplify
}

// Return a pointer to the first Node moving forward from
// the head of a circular that contains a given value or
// NULL if one is not found
Node *circular_find(Circular *list, int value) {
    return NULL;
}

// Return true if a Circular contains a Node with a
// given value or false if it does not
bool circular_contains(Circular *list, int value) {
    // Use circular_find
    return false;
}

// Remove a given Node from a Circular, decrement the size, 
// and free the Node.  Update the head pointer if the Node 
// is at the head of the Circular to the next Node
void circular_remove(Circular *list, Node *node) {
    // Make sure that the list isn't empty and consider separate
    // cases where the list contains only one Node or more than
    // one Node
    assert(list->head);
}

// Remove the Node at the head of a Circular and return its value. 
// Update the head to the next node in the list, and decrement the size
int  circular_pop_front(Circular *list) {
    // Take advantage of circular_remove
    assert(list->head);
    return NULL;
}

// Remove the Node at the tail of a Circular (before the head) and return its value. 
// Decrement the size
int  circular_pop_back(Circular *list) {
    // Take advantage of circular_remove
    assert(list->head);
    return NULL;
}

// Remove all the Nodes in a Circular and then free the Circular itself
void circular_delete(Circular *list) {
    // Take advantage of circular_remove
}
