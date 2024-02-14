#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int val;
    Node *next;
};

Node *node_create(int val, Node *next) {
    Node *node = malloc(sizeof (Node));
    node->val = val;
    node->next = next;
    return node;
}

int main() {
    Node *n1 = node_create(7,NULL);
    Node *n2 = node_create(3,NULL);
    Node *n3 = node_create(5,NULL);

    
}