#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the alphabet
#define q 101 // A prime number

void search(char pattern[], char text[])
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;
    
    // Calculate h = d^(m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    
    // Calculate hash value for pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    // Slide the pattern over the text one by one
    for (i = 0; i <= n - m; i++) {
        // Check if the hash values of the pattern and current window of text match
        if (p == t) {
            // Check if all characters in the pattern match the current window of text
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                printf("Pattern found at index %d\n", i);
        }
        // Calculate the hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char text[] = "cattoscat";
    char pattern[] = "cat";
    search(pattern, text);
    return 0;
}

