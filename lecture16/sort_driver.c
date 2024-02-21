#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "utils.h"

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void mergeSort(int arr[], int low, int high);
void quickSort(int array[], int low, int high);

void usage() {
    puts("Usage:");
    puts("sort_driver -s <sort_type> -n <size> -d <data> -p <print_array>");
    puts("b: bubble");
    puts("s: selection");
    puts("i: insertion");
    puts("m: merge");
    puts("q: quick");
    exit(EXIT_FAILURE);
}

// Driver program
int main(int argc, char **argv) {
    char sort_type = 'q';
    int size = (10);
    char data = 'r';    // (r)andom, (u)p, (d)own
    bool print = false;
    int argind = 1;

    // Parse command-line arguments
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *argument = argv[argind++];
        switch (argument[1]) {
            case 's': sort_type = argv[argind++][0]; break;
            case 'n': size = atoi(argv[argind++]); break;
            case 'd': data = argv[argind++][0]; break;
            case 'p': print = true; break;
            case 'h': usage(0); break;
            default: usage(1); break;
        }
    }

    int *arr = malloc(size * sizeof(int));

    switch (data) {
        case 'r': randomArray(arr, size); break;
        case 'u': increasingArray(arr, size); break;
        case 'd': decreasingArray(arr, size); break;
        default:
            printf("Unknown data specification\n");
            exit(EXIT_FAILURE);
            break;
    }

    if (print) {
        printf("Original array: \n");
        printArray(arr, size);
    }

    switch (sort_type) {
        case 'b':
            printf("bubble sort\n");
            bubbleSort(arr, size);
            break;
        case 's':
            printf("selection sort\n");
            selectionSort(arr, size);
            break;
        case 'i':
            printf("insertion sort\n");
            insertionSort(arr, size);
            break;
        case 'm':
            printf("merge sort\n");
            mergeSort(arr, 0, size-1);
            break;
        case 'q':
            printf("quick sort\n");
            quickSort(arr, 0, size-1);
            break;
    }

    assertSortedArray(arr, size);

    if (print) {
        printf("Sorted array: \n");
        printArray(arr, size);
    }

    free(arr);
    return EXIT_SUCCESS;
}