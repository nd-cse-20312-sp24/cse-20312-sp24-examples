/* people.c */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */

#define PEOPLE_MAX (1<<10)

/* Structures */

typedef struct {
    char   *name;
    size_t  age;
} Person;

/* Functions */

Person *person_create(char *s) {
    Person *p = calloc(1, sizeof(Person));	// Review: calloc vs malloc
    if (p) {
    	p->name = strdup(strtok(s, " "));	// BAD:  missing strdup
    	p->age  = atoi(strtok(NULL, " "));	// WARN: should do error checking
    }
    return p;
}

void	person_delete(Person *p) {
    free(p->name);				// Discuss: Why not p->age?
    free(p);
}

void	person_output(Person *p) {
    printf("%-10s %lu\n", p->name, p->age);	// Discuss: formatting tricks
}

int	person_compare(const void *a, const void *b) {
    Person *pa = *(Person **)a;			// Discuss: Why person **
    Person *pb = *(Person **)b;
    return strcmp(pa->name, pb->name);		// Discuss: How about age?
}

/* Main Execution */

int main(int argc, char *argv[]) {
    Person *people[PEOPLE_MAX] = {0};
    char    buffer[BUFSIZ];
    size_t  n;

    // Read each person into people array
    for (n = 0; fgets(buffer, BUFSIZ, stdin); n++) {
    	people[n] = person_create(buffer);
    }
    
    // Sort people array
    qsort(people, n, sizeof(Person *), person_compare);
    
    // Print each person in people array
    for (size_t i = 0; i < n; i++) {
    	person_output(people[i]);
    }

    // Free each person in people array
    for (Person **p = people; *p; p++) {	// Discuss: alternative iteration
    	person_delete(*p);			// Discuss: Why not just free(people)
    }

    return 0;
}
