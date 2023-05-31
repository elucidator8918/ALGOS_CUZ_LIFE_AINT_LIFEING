#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to find the k-th smallest element using Quick Select algorithm
int quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // If the pivot is the k-th smallest element
        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        // If the k-th smallest element is in the left subarray
        if (pivotIndex > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);

        // If the k-th smallest element is in the right subarray
        return quickSelect(arr, pivotIndex + 1, high, k);
    }

    // If the array has only one element
    return arr[low];
}

// Function to find the median of an unsorted array
double findMedian(int arr[], int n) {
    // If the array has an odd number of elements
    if (n % 2 != 0)
        return quickSelect(arr, 0, n - 1, n / 2 + 1);

    // If the array has an even number of elements
    int median1 = quickSelect(arr, 0, n - 1, n / 2);
    int median2 = quickSelect(arr, 0, n - 1, n / 2 + 1);

    return (double)(median1 + median2) / 2;
}

int main() {
    int arr[] = { 7, 2, 1, 6, 8, 5, 3, 4 , 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    double median = findMedian(arr, n);
    printf("Median: %lf\n", median);

    return 0;
}
