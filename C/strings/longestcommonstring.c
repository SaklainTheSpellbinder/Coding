#include <stdio.h>

// Utility function to find the length of a string
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to find the Longest Common Substring
void longestCommonSubstring(const char *str1, const char *str2, char *result) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    int dp[len1 + 1][len2 + 1];

    // Initialize the DP table
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            dp[i][j] = 0;
        }
    }

    int maxLength = 0;   // Maximum length of the common substring
    int endIndex = 0;    // Ending index of the LCS in str1

    // Build the DP table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1; // Track the ending position
                }
            }
        }
    }

    // Extract the LCS from str1
    for (int i = 0; i < maxLength; i++) {
        result[i] = str1[endIndex - maxLength + 1 + i];
    }
    result[maxLength] = '\0'; // Null-terminate the result
}

int main() {
    char str1[] = "abcdef";
    char str2[] = "zabc";
    char result[100];

    longestCommonSubstring(str1, str2, result);
    printf("Longest Common Substring: %s\n", result);

    return 0;
}
