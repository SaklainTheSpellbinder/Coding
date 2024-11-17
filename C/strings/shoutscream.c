#include <stdio.h>

void replaceSubstring(char s1[], char s2[], char s3[], char result[], int *count) {
    int i = 0, k = 0, temp, match;
    *count = 0;

    while (s1[i] != '\0') {
        match = 1;
        temp = i;

        // Check if s2 matches at position i in s1
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[temp] != s2[j]) {
                match = 0;
                break;
            }
            temp++;
        }

        // If s2 is found, replace it with s3
        if (match) {
            (*count)++;
            for (int j = 0; s3[j] != '\0'; j++) {
                result[k++] = s3[j];
            }
            i += temp - i; // Skip the length of s2 in s1
        } else {
            result[k++] = s1[i++]; // Copy current character from s1 to result
        }
    }

    result[k] = '\0'; // Null-terminate the resulting string
}

int main() {
    char s1[] = "I scream, you scream, we all scream for ice cream!";
    char s2[] = "scream";
    char s3[] = "shout";
    char result[200]; // Ensure this is large enough for the result
    int count;

    replaceSubstring(s1, s2, s3, result, &count);

    printf("Resulting string: %s\n", result);
    printf("Number of replacements: %d\n", count);

    return 0;
}
