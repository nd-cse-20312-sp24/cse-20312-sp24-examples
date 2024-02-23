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

}

Node *list_append_head(Node *head, int val) { 

}

void list_print(Node *head) {

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