#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle the characters in a string
void shuffleString(char *str) {
    int n = strlen(str);
    // Seed the random number generator
    srand(time(0));

    for (int i = n - 1; i > 0; i--) {
        // Generate a random index from 0 to i
        int j = rand() % (i + 1);
        // Swap the characters at indices i and j
        swap(&str[i], &str[j]);
    }
}

// Function to check if a string is full of the same character
int isFullOfSameCharacter(char *str) {
    int length = strlen(str);
    if (length == 0) return 1; // An empty string is trivially full of the same character

    char firstChar = str[0];
    for (int i = 1; i < length; i++) {
        if (str[i] != firstChar) {
            return 0; // Found a different character
        }
    }
    return 1; // All characters are the same
}

int main() {
    char s[100];
    char r[100];
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();  // to consume the newline character after reading n

    for (int i = 1; i <= n; i++) {
        printf("Enter string %d: ", i);
        scanf(" %[^\n]", s);  // Read a line of input

        if (isFullOfSameCharacter(s) == 1) {
            printf("NO\n");
        } else {
            printf("YES\n");
            strcpy(r, s);
            shuffleString(r);
            printf("%s\n", r);
        }
    }
    return 0;
}
