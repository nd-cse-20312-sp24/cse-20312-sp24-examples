#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "circular.h"

// Test that all next and prev links in a Circular are properly connected.
// Run a full lap around a Circular in both the forward and reverse 
// directions and make sure that you end up back at the head.
bool test_circular_connectivity(Circular *list) {
    bool result = false;
    Node *curr = list->head;
    for (int i = 0; i < list->size; i++) {
        curr = curr->next;
    }
    assert(curr == list->head);

    for (int i = 0; i < list->size; i++) {
        curr = curr->prev;
    }
    assert(curr == list->head);

    result = true;
    return result;
}

bool test_00_circular_create() {
    Circular *list = circular_create();
    assert(list->head == NULL);
    assert(list->size == 0);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_01_circular_push_front() {
    Circular *list = circular_create();
    circular_push_front(list, 102);
    circular_push_front(list, 101);
    circular_push_front(list, 100);
    assert(list->size == 3);
    assert(list->head->value == 100);
    assert(list->head->next->value == 101);
    assert(list->head->next->next->value == 102);
    assert(list->head->next->next->next->value == 100);
    assert(list->head->prev->value == 102);
    assert(list->head->prev->prev->value == 101);
    assert(list->head->prev->prev->prev->value == 100);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_02_circular_empty() {
    Circular *list = circular_create();
    assert(circular_empty(list) == true);
    circular_push_front(list, 1);
    assert(circular_empty(list) == false);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_03_circular_insert_after() {
    Circular *list = circular_create();
    circular_push_front(list, 100);
    circular_insert_after(list, list->head, 101);
    circular_insert_after(list, list->head->next, 102);
    circular_insert_after(list, list->head->prev, 103);
    assert(list->size == 4);
    assert(list->head->value == 100);
    assert(list->head->next->value == 101);
    assert(list->head->next->next->value == 102);
    assert(list->head->next->next->next->value == 103);
    assert(test_circular_connectivity(list));
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_04_circular_insert_before() {
    Circular *list = circular_create();
    circular_push_front(list, 100);
    circular_insert_before(list, list->head, 103);
    circular_insert_before(list, list->head->next, 101);
    circular_insert_before(list, list->head->prev, 102);
    assert(list->size == 4);
    assert(list->head->value == 100);
    assert(list->head->next->value == 101);
    assert(list->head->next->next->value == 102);
    assert(list->head->next->next->next->value == 103);
    assert(test_circular_connectivity(list));
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_05_circular_push_back() {
    Circular *list = circular_create();
    circular_push_back(list, 100);
    circular_push_back(list, 101);
    circular_push_back(list, 102);
    assert(list->size == 3);
    assert(list->head->value == 100);
    assert(list->head->next->value == 101);
    assert(list->head->next->next->value == 102);
    assert(list->head->next->next->next->value == 100);
    assert(list->head->prev->value == 102);
    assert(list->head->prev->prev->value == 101);
    assert(list->head->prev->prev->prev->value == 100);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_06_circular_find() {
    Circular *list = circular_create();
    circular_push_front(list, 102);
    circular_push_front(list, 101);
    circular_push_front(list, 100);
    assert(circular_find(list, 100) == list->head);
    assert(circular_find(list, 101) == list->head->next);
    assert(circular_find(list, 102) == list->head->prev);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_07_circular_contains() {
    Circular *list = circular_create();
    circular_push_front(list, 100);
    assert(circular_contains(list, 100) == true);
    assert(circular_contains(list, 101) == false);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_08_circular_remove() {
    Circular *list = circular_create();
    circular_push_front(list, 103);
    circular_push_front(list, 102);
    circular_push_front(list, 101);
    circular_push_front(list, 100);
    assert(list->size == 4);
    circular_remove(list, list->head->next);
    assert(list->size == 3);
    assert(list->head->next->value == 102);
    assert(list->head->prev->value == 103);
    assert(list->head->prev->prev->value == 102);
    assert(test_circular_connectivity(list));
    circular_remove(list, list->head->prev);
    assert(list->head->prev->value == 102);
    assert(test_circular_connectivity(list));
    circular_remove(list, list->head);
    circular_remove(list, list->head);
    assert(list->size == 0);
    assert(list->head == NULL);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_09_circular_pop_front() {
    Circular *list = circular_create();
    circular_push_front(list, 102);
    circular_push_front(list, 101);
    circular_push_front(list, 100);
    assert(circular_pop_front(list) == 100);
    assert(test_circular_connectivity(list));
    assert(circular_pop_front(list) == 101);
    assert(test_circular_connectivity(list));
    assert(circular_pop_front(list) == 102);
    assert(circular_empty(list));
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_10_circular_pop_back() {
    Circular *list = circular_create();
    circular_push_back(list, 100);
    circular_push_back(list, 101);
    circular_push_back(list, 102);
    assert(circular_pop_back(list) == 102);
    assert(test_circular_connectivity(list));
    assert(circular_pop_back(list) == 101);
    assert(test_circular_connectivity(list));
    assert(circular_pop_back(list) == 100);
    assert(circular_empty(list));
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_11_circular_delete() {
    Circular *list = circular_create();
    circular_push_front(list, 102);
    circular_push_front(list, 101);
    circular_push_front(list, 100);
    circular_delete(list);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
        fprintf(stderr, "Where NUMBER is one of the following:\n");
        fprintf(stderr, "    0  Test circular_create\n");
        fprintf(stderr, "    1  Test circular_push_front\n");
        fprintf(stderr, "    2  Test circular_empty\n");
        fprintf(stderr, "    3  Test circular_insert_after\n");
        fprintf(stderr, "    4  Test circular_insert_before\n");
        fprintf(stderr, "    5  Test circular_push_back\n");
        fprintf(stderr, "    6  Test circular_find\n");
        fprintf(stderr, "    7  Test circular_contains\n");
        fprintf(stderr, "    8  Test circular_remove\n");
        fprintf(stderr, "    9  Test circular_pop_front\n");
        fprintf(stderr, "    10 Test circular_pop_back\n");
        fprintf(stderr, "    11 Test circular_delete\n");
        return EXIT_FAILURE;
    }

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
        case 0: status = test_00_circular_create(); break;
        case 1: status = test_01_circular_push_front(); break;
        case 2: status = test_02_circular_empty(); break;
        case 3: status = test_03_circular_insert_after(); break;
        case 4: status = test_04_circular_insert_before(); break;
        case 5: status = test_05_circular_push_back(); break;
        case 6: status = test_06_circular_find(); break;
        case 7: status = test_07_circular_contains(); break;
        case 8: status = test_08_circular_remove(); break;
        case 9: status = test_09_circular_pop_front(); break;
        case 10: status = test_10_circular_pop_back(); break;
        case 11: status = test_11_circular_delete(); break;
        default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }
    return status;
}