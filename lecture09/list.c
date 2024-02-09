/* Lecture 09: Linked List */

#include "list.h"
#include<assert.h>

/* Node Structure */

Node *	node_create(int data, Node *next) {
    Node *n = malloc(sizeof(Node));
    if (n) {
    	n->data = data;
    	n->next = next;
    }
    return n;
}

void	node_delete(Node *n) {
    if (!n) {
    	return;
    }
    free(n);
}

/* List Structure */
List *list_create() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

bool list_empty(List *list) {
    return list->head == NULL;
}

void list_delete(List *list) {
    while (list->head != NULL) {
        list_pop(list);
    }
    free(list);
}

void list_push(List *list, int value) {
    list->head = node_create(value, list->head);
}

int	list_pop(List *list) {
    assert(list->head);
    Node *n = list->head;
    list->head = list->head->next;

    int value = n->data;
    node_delete(n);
    return value;
}

int	list_index(List *list, int value) {
    int index = 0;
    for (Node *curr = list->head; curr; curr = curr->next) {
    	if (curr->data == value)
    	    return index;
    	index++;
    }
    return -1;
}

int	list_at(List *list, int index) {
    int cindex = 0;
    Node  *curr   = list->head;

    while (curr && cindex != index) {
    	curr = curr->next;
    	cindex++;
    }

    return (curr && cindex == index) ? curr->data : -1;
}

void list_insert(List *list, int index, int value) {
    if (index == 0) {
        list_push(list, value);
    } else {
        Node *curr = list->head;
        for (int i = 0;  i < index - 1;  curr = curr->next) {}
        Node *n = node_create(value, curr->next);
        curr->next = n;
    }
}

void list_remove(List *list, int index) {
    if (index == 0) {
        list_pop(list);
    } else {
        Node *curr = list->head;
        for (int i = 0;  i < index - 1;  curr = curr->next) {}
        Node *n = curr->next;
        curr->next = n->next;
        node_delete(n);
    }
}
