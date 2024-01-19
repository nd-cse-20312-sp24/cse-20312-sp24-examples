#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "duplicates.h"

#define PROBSIZE (1 << 4)

int array_nodup[4] = {1, 2, 4, 8};
int array_dup[4] = {1, 2, 8, 8};

int status = EXIT_FAILURE;

int *seq_array(size_t n)
{
    int *a = malloc(n * sizeof(int));
    for (int i = 0;  i < n;  i++) {
        a[i] = i*i;
    }
    return a;
}

int test00_has_duplicates00() {
    assert(has_duplicates00(array_dup, 4) == true);
    assert(has_duplicates00(array_nodup, 4) == false);
    int *seq = seq_array(PROBSIZE);
    assert(has_duplicates00(seq, PROBSIZE) == false);
    seq[PROBSIZE-1] = seq[PROBSIZE-2]; 
    assert(has_duplicates00(seq, PROBSIZE) == true);
    free(seq);
    return EXIT_SUCCESS;
}

int test01_has_duplicates01() {
    assert(has_duplicates01(array_dup, 4) == true);
    assert(has_duplicates01(array_nodup, 4) == false);
    int *seq = seq_array(PROBSIZE);
    assert(has_duplicates01(seq, PROBSIZE) == false);
    seq[PROBSIZE-1] = seq[PROBSIZE-2]; 
    assert(has_duplicates01(seq, PROBSIZE) == true);
    free(seq);
    return EXIT_SUCCESS;
}

int main()
{
    printf("starting\n");
    status = test00_has_duplicates00();
    printf("finished test00\n");
    status = test01_has_duplicates01();
    printf("finished test01\n");
    return EXIT_SUCCESS;
}