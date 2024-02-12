#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool test_00_list_create() {
    Node *n = node_create(10, NULL);
    List* list = list_create();
    list->head = n;
    assert(list->head->data == 10);
    free(list->head);
    free(list);
    return EXIT_SUCCESS;
}

bool test_01_list_push() {
    List* list = list_create();
    list_push(list, 10);
    list_push(list, 20);
    assert(list->head->data == 20);
    assert(list->head->next->data == 10);
    free(list->head->next);
    free(list->head);
    free(list);
    return(EXIT_SUCCESS);
}

bool test_02_list_pop() {
    List* list = list_create();
    list_push(list, 10);
    list_push(list, 20);
    assert(list_pop(list) == 20);
    assert(list_pop(list) == 10);
    assert(list->head == NULL);
    free(list);
    return(EXIT_SUCCESS);
}

bool test_03_list_delete() {
    List* list = list_create();
    list_push(list, 10);
    list_push(list, 20);
    list_delete(list);
    return(EXIT_SUCCESS);
}

bool test_04_list_empty() {
    List* list = list_create();
    assert(list_empty(list) == true);
    list_push(list, 10);
    assert(list_empty(list) == false);
    list_delete(list);
    return(EXIT_SUCCESS);
}

bool test_05_list_index() {
    List* list = list_create();
    list_push(list, 10);
    list_push(list, 20);
    list_push(list, 30);
    assert(list_index(list, 30) == 0);
    assert(list_index(list, 20) == 1);
    assert(list_index(list, 10) == 2);
    assert(list_index(list, 40) == -1);
    list_delete(list);
    return(EXIT_SUCCESS);
}

bool test_06_list_at() {
    List* list = list_create();
    list_push(list, 10);
    list_push(list, 20);
    list_push(list, 30);
    assert(list_at(list, 0) == 30);
    assert(list_at(list, 1) == 20);
    assert(list_at(list, 2) == 10);
    list_delete(list);
    return(EXIT_SUCCESS);
}

bool test_07_list_insert() {
    List* list = list_create();
    list_insert(list, 0, 100);
    list_insert(list, 1, 103);
    list_insert(list, 1, 101);
    list_insert(list, 2, 102);
    list_insert(list, 4, 104);
    assert(list_at(list, 0) == 100);
    assert(list_at(list, 1) == 101);
    assert(list_at(list, 2) == 102);
    assert(list_at(list, 3) == 103);
    assert(list_at(list, 4) == 104);
    list_delete(list);
    return(EXIT_SUCCESS);
}

bool test_08_list_remove() {
    List* list = list_create();
    list_push(list, 10);
    list_push(list, 20);
    list_push(list, 30);
    list_remove(list, 1);
    assert(list_at(list, 0) == 30);
    assert(list_at(list, 1) == 10);
    list_remove(list, 1);
    assert(list_at(list, 0) == 30);
    list_delete(list);
    return(EXIT_SUCCESS);
}

int main(int argc, char const *argv[])
{
    test_00_list_create();
    test_01_list_push();
    test_02_list_pop();
    test_03_list_delete();
    test_04_list_empty();
    test_05_list_index();
    test_06_list_at();
    test_07_list_insert();
    test_08_list_remove();
    return 0;
}
