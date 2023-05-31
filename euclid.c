#include <stdio.h>

int euclideanAlgorithm(int a, int b)
{
    if (b == 0)
    return a;
    return euclideanAlgorithm(b, a % b);
}

void main() {
    int a, b;
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, euclideanAlgorithm(a, b));
}
