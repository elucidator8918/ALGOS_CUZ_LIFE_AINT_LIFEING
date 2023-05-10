#include <stdio.h>

int isSubsetSum(int set[], int n, int sum)
{
    // The base case
    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;

    // If last element is greater than sum,
    // then ignore it
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);

    /* else, check if sum can be obtained by either
     * including the last element or excluding it
     */
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);

    if (isSubsetSum(set, n, sum) == 1)
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");
    return 0;
}
