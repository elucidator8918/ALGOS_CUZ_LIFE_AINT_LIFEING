#include <stdio.h>
#include <string.h>

// Compute the prefix function for the pattern
void compute_prefix_function(char *pattern, int *prefix_function, int pattern_len) {
    int border = 0;
    prefix_function[0] = 0;

    for (int i = 1; i < pattern_len; i++) 
    {
        while (border > 0 && pattern[i] != pattern[border])
          border = prefix_function[border-1];
        if (pattern[i] == pattern[border])
          border++;
        else
          border = 0;        
        prefix_function[i] = border;
    }
}

// Search for occurrences of the pattern in the text using the prefix function
void kmp(char *text, char *pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int prefix_function[pattern_len];

    compute_prefix_function(pattern, prefix_function, pattern_len);

    int j = 0;
    for (int i = 0; i < text_len; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix_function[j-1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == pattern_len) {
            printf("Found pattern at index %d\n", i - pattern_len + 1);
            j = prefix_function[j-1];
        }
    }
}

void main() {
    char text[] = "cattoscatty";
    char pattern[] = "cat";
    kmp(text, pattern);    
}

