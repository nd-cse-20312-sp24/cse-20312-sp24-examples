#include "circular.h"
#include <stdio.h>

int main() {
    Circular *list = circular_create();
    circular_push_front(list, 3);
    circular_push_front(list, 2);
    circular_push_front(list, 1);

}
