#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) 
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void main() {
    int arr[] = {5, 2, 8, 4, 6, 1, 3, 7};
    clock_t start,end;
    int n = sizeof(arr) / sizeof(arr[0]);
    start=clock();
    quicksort(arr, 0, n - 1);
    end=clock();
    printf("Time Consumed = %ld\n",end-start);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);    
}
