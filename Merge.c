#include <stdio.h>
#include <time.h>
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) 
    L[i] = arr[l + i];    
    for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];    

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    clock_t start,end;    
    printf("Given array is \n");
    printArray(arr, arr_size);
    start=clock();
    mergeSort(arr, 0, arr_size - 1);
    end=clock();
    printf("Time Consumed = %ld",end-start);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
}

