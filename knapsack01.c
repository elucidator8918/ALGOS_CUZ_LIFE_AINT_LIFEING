#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent each item
typedef struct {
    int weight;
    int value;
} item;

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming and print the items chosen
void knapsack(int capacity, item* items, int n) {
    int i, w;
    int K[n+1][capacity+1];
    int chosen[n];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i-1].weight <= w)
                K[i][w] = max(items[i-1].value + K[i-1][w-items[i-1].weight], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    int max_value = K[n][capacity];
    int remaining_weight = capacity;
    int j = n;
    int num_chosen = 0;

    // Traverse the table K[][] to find the items chosen
    while (j > 0 && max_value > 0) {
        if (max_value != K[j-1][remaining_weight]) {
            chosen[num_chosen++] = j-1;
            max_value -= items[j-1].value;
            remaining_weight -= items[j-1].weight;
        }
        j--;
    }

    // Print the items chosen to give the maximum amount
    printf("Items chosen: ");
    for (i = num_chosen-1; i >= 0; i--)
        printf("%d ", chosen[i]+1);
    printf("\nMaximum value: %d\n", K[n][capacity]);
}

// Driver program to test above function
int main() {
    item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 40;
    int n = sizeof(items)/sizeof(items[0]);

    knapsack(capacity, items, n);

    return 0;
}

