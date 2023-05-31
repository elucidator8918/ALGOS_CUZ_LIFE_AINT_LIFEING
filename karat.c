#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the number of digits in a given number
int numDigits(long long int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Karatsuba multiplication algorithm
long long int karatsubaMultiply(long long int x, long long int y) {
    // Base case: if the numbers are single-digit, perform simple multiplication
    if (x < 10 || y < 10) {
        return x * y;
    }
  
    // Calculate the number of digits in x and y
    int n = fmax(numDigits(x), numDigits(y));
  
    // Calculate the value of m, which is the number of digits divided by 2
    int m = (n / 2) + (n % 2);
  
    // Split the given numbers into high and low parts
    long long int high1 = x / (long long int)pow(10, m);
    long long int low1 = x % (long long int)pow(10, m);
    long long int high2 = y / (long long int)pow(10, m);
    long long int low2 = y % (long long int)pow(10, m);
  
    // Recursively compute the three multiplications
    long long int z0 = karatsubaMultiply(low1, low2);
    long long int z1 = karatsubaMultiply((low1 + high1), (low2 + high2));
    long long int z2 = karatsubaMultiply(high1, high2);
  
    // Calculate the cross terms
    long long int crossTerm = z1 - z0 - z2;
  
    // Compute the final product using the formula: xy = z2 * 10^(2m) + crossTerm * 10^m + z0
    long long int result = (z2 * (long long int)pow(10, (2 * m))) + (crossTerm * (long long int)pow(10, m)) + z0;
  
    return result;
}

// Main function
int main() {
    long long int x, y;
    printf("Enter two numbers to multiply: ");
    scanf("%lld %lld", &x, &y);
  
    long long int result = karatsubaMultiply(x, y);
    printf("Product: %lld\n", result);
  
    return 0;
}
