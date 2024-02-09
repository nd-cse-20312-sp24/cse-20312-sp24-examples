/* Lecture 09: Linked List */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

/* Node Structure */

typedef struct Node Node;
struct Node {
    int   data;	    // Value associated with Node
    Node *next;	    // Pointer to next Node in List
};

Node *	node_create(int data, Node *next);
void	node_delete(Node *n);

/* List Structure */

typedef struct {
    Node *head;	    // Pointer to first Node in List
} List;

List*   list_create();
void    list_delete(List *list);
bool    list_empty(List *list);
void    list_push(List *list, int value);
int	    list_pop(List *list);
int	    list_index(List *list, int value);
int	    list_at(List *list, int index);
void    list_insert(List *list, int index, int value);
void    list_remove(List *list, int index);
