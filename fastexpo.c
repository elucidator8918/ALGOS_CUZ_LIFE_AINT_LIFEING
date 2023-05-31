#include <stdio.h>

long long fast_exponentiation(long long base, long long exponent) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }

    return result;
}

int main() {
    long long base, exponent;
    printf("Enter the base number: ");
    scanf("%lld", &base);
    printf("Enter the exponent: ");
    scanf("%lld", &exponent);

    long long result = fast_exponentiation(base, exponent);
    printf("%lld raised to the power of %lld is %lld\n", base, exponent, result);

    return 0;
}
