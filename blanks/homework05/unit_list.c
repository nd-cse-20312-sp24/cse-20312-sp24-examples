#include "list.h"

bool test_00_node_create() {
    Node *n0 = node_create(100, NULL);
    Node *n1 = node_create(101, n0);
    assert(n1->val == 101);
    assert(n1->next->val == 100);
    assert(n1->next->next == NULL);
    node_delete(n0);
    node_delete(n1);
    return EXIT_SUCCESS;
}

bool test_01_list_delete() {
    Node *n0 = node_create(100, NULL);
    Node *n1 = node_create(101, n0);
    Node *n2 = node_create(102, n1);
    list_delete(n2);
    return EXIT_SUCCESS;
}

bool test_02_list_append_head() {
    Node *head = NULL;
    head = list_append_head(head, 100);
    head = list_append_head(head, 101);
    head = list_append_head(head, 102);
    assert(head->val == 102);
    assert(head->next->val == 101);
    assert(head->next->next->val == 100);
    list_delete(head);
    return EXIT_SUCCESS;
}

bool test_03_list_append_tail() {
    Node *head = NULL;
    head = list_append_tail(head, 100);
    head = list_append_tail(head, 101);
    head = list_append_tail(head, 102);
    assert(head->val == 100);
    assert(head->next->val == 101);
    assert(head->next->next->val == 102);
    list_delete(head);
    return EXIT_SUCCESS;
}

bool test_04_list_split() {
    // test even number of nodes
    Node *head = NULL;
    Node *left = NULL;
    Node *right = NULL;
    for (int i = 6;  i >= 1;  i--) {
        head = list_append_head(head, i);
    }
    list_split(head, &left, &right);
    assert(left->val == 1);
    assert(left->next->val == 2);
    assert(left->next->next->val == 3);
    assert(left->next->next->next == NULL);
    assert(right->val == 4);
    assert(right->next->val == 5);
    assert(right->next->next->val == 6);
    assert(right->next->next->next == NULL);
    list_delete(left);
    list_delete(right);

    // test odd number of nodes
    head = NULL;
    left = NULL;
    right = NULL;
    for (int i = 3;  i >= 1;  i--) {
        head = list_append_head(head, i);
    }
    list_split(head, &left, &right);
    assert(left->val == 1);
    assert(left->next == NULL);
    assert(right->val == 2);
    assert(right->next->val == 3);
    assert(right->next->next == NULL);
    list_delete(left);
    list_delete(right);
    return EXIT_SUCCESS;
}

bool test_05_list_merge() {
    Node *head = NULL;
    Node *left = NULL;
    Node *right = NULL;
    left = list_append_head(left, 1);
    right = list_append_head(right, 2);
    head = list_merge(left, right);
    assert(head->val == 1);
    assert(head->next->val == 2);
    list_delete(head);

    head = NULL;
    left = NULL;
    right = NULL;
    left = list_append_head(left, 2);
    right = list_append_head(right, 1);
    head = list_merge(left, right);
    assert(head->val == 1);
    assert(head->next->val == 2);
    list_delete(head);

    head = NULL;
    left = NULL;
    right = NULL;
    for (int i = 6;  i >= 2;  i = i - 2) {
        left = list_append_head(left, i);
    }
    for (int i = 7;  i >= 1;  i = i - 2) {
        right = list_append_head(right, i);
    }
    head = list_merge(left, right);
    int i = 1;
    Node *cur = head;
    while (cur != NULL) {
        assert(cur->val == i);
        cur = cur->next;
        i++;
    }
    list_delete(head);
    return EXIT_SUCCESS;
}

bool test_06_list_merge_sort() {
    Node *head = NULL;
    head = list_append_head(head, 3);
    head = list_append_head(head, 1);
    head = list_append_head(head, 4);
    head = list_append_head(head, 5);
    head = list_append_head(head, 2);
    head = list_merge_sort(head);
    int i = 1;
    Node *cur = head;
    while (cur != NULL) {
        assert(cur->val == i);
        cur = cur->next;
        i++;
    }
    list_delete(head);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
        fprintf(stderr, "Where NUMBER is one of the following:\n");
        fprintf(stderr, "    0  Test node_create\n");
        fprintf(stderr, "    1  Test list_delete\n");
        fprintf(stderr, "    2  Test list_append_head\n");
        fprintf(stderr, "    3  Test list_append_tail\n");
        fprintf(stderr, "    4  Test list_split\n");
        fprintf(stderr, "    5  Test list_merge\n");
        fprintf(stderr, "    6  Test list_merge_sort\n");
        return EXIT_FAILURE;
    }

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
        case 0: status = test_00_node_create(); break;
        case 1: status = test_01_list_delete(); break;
        case 2: status = test_02_list_append_head(); break;
        case 3: status = test_03_list_append_tail(); break;
        case 4: status = test_04_list_split(); break;
        case 5: status = test_05_list_merge(); break;
        case 6: status = test_06_list_merge_sort(); break;
        default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }
    return status;
}