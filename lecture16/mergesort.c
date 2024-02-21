// Merge sort in C

#include <stdio.h>
#include <stdlib.h>

// Merge two subarrays L and R into arr
void merge(int arr[], int low, int mid, int high) {
    // Create L ← A[p..q] and R ← A[q+1..r]
    int n_left = mid - low + 1;
    int n_right = high - mid;

    // int L[n_left];
    // int R[n_right];

    int *L = malloc(n_left * sizeof(int));
    int *R = malloc(n_right * sizeof(int));

    for (int i = 0; i < n_left; i++) {
        L[i] = arr[low + i];
    }
    for (int i = 0; i < n_right; i++) {
        R[i] = arr[mid + 1 + i];
    }

    // Maintain current index of sub-arrays and main array
    int i_left = 0;
    int i_right = 0;
    int k = low;

    // Until we reach either end of either L or M, pick larger among
    // elements L and R and place them in the correct position at A[p..r]
    while (i_left < n_left && i_right < n_right) {
        if (L[i_left] <= R[i_right]) {
            arr[k] = L[i_left];
            i_left++;
        } else {
            arr[k] = R[i_right];
            i_right++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i_left < n_left) {
        arr[k] = L[i_left];
        i_left++;
        k++;
    }

    while (i_right < n_right) {
        arr[k] = R[i_right];
        i_right++;
        k++;
    }

    free(L);
    free(R);
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        // m is the point where the array is divided into two subarrays
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted subarrays
        merge(arr, low, mid, high);
    }
}
