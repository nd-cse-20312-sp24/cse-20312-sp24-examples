#include "utils.h"
#include <assert.h>

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void assertSortedArray(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    assert(arr[i] >= arr[i-1]);
  }
}

void increasingArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void decreasingArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    } 
}

void randomArray(int *arr, int size) {
    srand(0xabcdef);
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    } 
}

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}