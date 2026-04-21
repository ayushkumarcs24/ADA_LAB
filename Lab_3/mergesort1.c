#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int test_sizes[] = {1000, 10000, 100000, 1000000}; // different n values
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);

    srand(time(NULL)); // seed random generator

    for (int t = 0; t < num_tests; t++) {
        int n = test_sizes[t];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for n = %d\n", n);
            continue;
        }

        // Generate random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        // Measure time
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("n = %d, Time taken = %f seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
} 