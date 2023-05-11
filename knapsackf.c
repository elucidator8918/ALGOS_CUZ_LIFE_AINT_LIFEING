#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    else
        return 0;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    qsort(arr, n, sizeof(Item), compare);
    int i;
    double result = 0.0;
    printf("Selected items:\n");
    for (i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            result += arr[i].value;
            W -= arr[i].weight;
            printf("Item %d: 100%%\n", i+1);
        }
        else {
            double fraction = (double)W / arr[i].weight;
            result += arr[i].value * fraction;
            printf("Item %d: %.2lf%%\n", i+1, fraction*100);
            break;
        }
    }
    return result;
}

int main() {
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(Item);
    int W = 60;
    printf("Maximum value we can obtain = %.2lf\n", fractionalKnapsack(W, arr, n));
    return 0;
}

