#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int val;
    Node *next;
};

Node *node_create(int val, Node *next) {
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->next = next;
    return n;
}

void node_delete(Node *n) { 
    free(n); 
}

void list_delete(Node *n) {
    if (n == NULL) {
        return;
    }

    list_delete(n->next);
    node_delete(n);
}

Node *list_append_head(Node *head, int val) { 
    return node_create(val, head); 
}

void list_print(Node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", head->val);
    list_print(head->next);
}

int main() {
    Node *list = NULL;
    for (int i = 1;  i <= 10;  i++) {
        list = list_append_head(list, i);
    }
    list_print(list);
    list_delete(list);
    return EXIT_SUCCESS;
}