#include <stdio.h>

int isSubsetSum(int set[], int n, int sum, int subset[])
{
    // The base case
    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;

    // If last element is greater than sum,
    // then ignore it
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum, subset);

    /* else, check if sum can be obtained by either
     * including the last element or excluding it
     */
    if (isSubsetSum(set, n-1, sum, subset))
        return 1;

    subset[n-1] = 1;

    if (isSubsetSum(set, n-1, sum-set[n-1], subset))
        return 1;

    subset[n-1] = 0;

    return 0;
}

void printSubset(int set[], int n, int subset[])
{
    printf("The subset with the given sum is: ");
    for (int i = 0; i < n; i++)
    {
        if (subset[i] == 1)
            printf("%d ", set[i]);
    }
    printf("\n");
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);

    int subset[n];
    for (int i = 0; i < n; i++)
        subset[i] = 0;

    if (isSubsetSum(set, n, sum, subset) == 1)
        printSubset(set, n, subset);
    else
        printf("No subset with given sum\n");

    return 0;
}

