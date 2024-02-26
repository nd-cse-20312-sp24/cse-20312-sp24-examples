#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int val;
    Node *next;
};

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;

Node *node_create(int val, Node *next);
void node_delete(Node *n);

void list_delete(Node *head);

Node *list_append_head(Node *head, int val);
Node *list_append_tail(Node *head, int val);
void list_print(Node *n);

void list_split(Node *head, Node **left, Node **right);
Node *list_merge(Node *left, Node *right);

Node *list_merge_sort(Node *head);
