#include "circular.h"
#include <assert.h>
#include <stdbool.h>

bool test_circular_connectivity(Circular *list) {
    bool result = false;
    Node *curr = list->head;
    for (int i = 0;  i < list->size; i++) {
        curr = curr->next;
    }
    assert(curr == list->head);
    for (int i = 0;  i < list->size; i++) {
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
    assert(test_circular_connectivity(list));
    assert(list->head->value == 100);
    assert(list->head->next->value == 101);
    assert(list->head->next->next->value == 102);
    assert(list->head->next->next->next->value == 103);
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
    assert(test_circular_connectivity(list));
    assert(list->head->next->value == 102);
    assert(list->head->prev->value == 103);
    assert(list->head->prev->prev->value == 102);
    circular_remove(list, list->head->prev);
    assert(test_circular_connectivity(list));
    assert(list->head->prev->value == 102);
    circular_delete(list);
    return EXIT_SUCCESS;
}

bool test_09_circular_pop_front() {
    Circular *list = circular_create();
    circular_push_front(list, 102);
    circular_push_front(list, 101);
    circular_push_front(list, 100);
    assert(circular_pop_front(list) == 100);
    assert(circular_pop_front(list) == 101);
    assert(circular_pop_front(list) == 102);
    return EXIT_SUCCESS;
}

bool test_10_circular_pop_back() {
    Circular *list = circular_create();
    circular_push_back(list, 100);
    circular_push_back(list, 101);
    circular_push_back(list, 102);
    assert(circular_pop_back(list) == 102);
    assert(circular_pop_back(list) == 101);
    assert(circular_pop_back(list) == 100);
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

int main() {
    test_00_circular_create();
    test_01_circular_push_front();
    // test_02_circular_empty();
    test_03_circular_insert_after();
    // test_04_circular_insert_before();
    // test_05_circular_push_back();
    // test_06_circular_find();
    // test_07_circular_contains();
    test_08_circular_remove();
    // test_09_circular_pop_front();
    // test_10_circular_pop_back();
    test_11_circular_delete();
}