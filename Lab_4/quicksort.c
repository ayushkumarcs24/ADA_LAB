#include <stdio.h>
#include <time.h>


void quicksort(int a[], int low, int high) {
    int i = low, j = high;
    int pivot = a[low];
    int temp;

    if (low < high) {
        while (i < j) {
            while (a[i] <= pivot && i < high)
                i++;
            while (a[j] > pivot)
                j--;

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        a[low] = a[j];
        a[j] = pivot;

        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main() {
    int n, i, a[100];
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();   

    quicksort(a, 0, n - 1);

    end = clock();     

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTime taken = %f seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}