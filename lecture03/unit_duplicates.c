#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "duplicates.h"

int array_nodup[4] = {1, 2, 4, 8};
int array_dup[4]   = {1, 2, 8, 8};

int status = EXIT_FAILURE;

int test00_has_duplicates_slow() {
    assert(has_duplicates_slow(array_dup, 4) == true);
    assert(has_duplicates_slow(array_nodup, 4) == false);
    return EXIT_SUCCESS;
}

int test01_has_duplicates_fast() {
    assert(has_duplicates_fast(array_dup, 4) == true);
    assert(has_duplicates_fast(array_nodup, 4) == false);
    return EXIT_SUCCESS;
}

int main()
{
    status = test00_has_duplicates_slow();
    status = test01_has_duplicates_fast();
    return status;
}