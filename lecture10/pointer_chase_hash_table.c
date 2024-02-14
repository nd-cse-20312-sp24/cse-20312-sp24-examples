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
    Node *n2 = node_create(5,NULL);
    Node **hash_table = malloc(6 * sizeof(Node*));

    hash_table[3] = n1;
    hash_table[3]->next = n2;
    printf("%d\n", hash_table[3]->next->val);
}