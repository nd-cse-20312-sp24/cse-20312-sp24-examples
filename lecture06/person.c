#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int  age;
} Person;

Person *person_create(char *s, size_t a) {
    // TODO
    Person *p = malloc(sizeof(Person));
    p->name = strdup(s);
    p->age = a;
    return p;
}

void person_print(Person *p) {
    printf("Name: %-10s  Age: %d\n", p->name, p->age);
}

void person_free(Person *p) {
    // TODO
    free(p->name);
    free(p);
}

int main() {
    // TODO: Knute age 21
    Person p1;
    p1.name = "Knute";
    p1.age = 21;
    
    printf("sizeof(Person): %lu\n", sizeof(Person));
    printf("&(p1.name): %p\n", &(p1.name));
    printf("&(p1.age):  %p\n", &(p1.age));

    // TODO: Ara age 23
    Person p2 = {"Ara", 25};

    // TODO: use person_create for Lou age 19
    Person *p3 = person_create("Lou", 19);

    // TODO: print p1, p2, p3
    person_print(p3);
    person_print(&p1);
    person_print(&p2);

    // TODO: free dynamically allocated objects
    person_free(p3);

    return EXIT_SUCCESS;
}