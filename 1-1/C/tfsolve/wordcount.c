

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];
    scanf("%[^\n]", str); // Read the full line including spaces

    int count = 0;
    int inWord = 0; // Flag to check if we are inside a word

    for (int i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) { // If it's not a space
            if (inWord == 0) {  // Found a new word
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0; // Reset flag when encountering a space
        }
    }

    printf("%d\n", count); // Print the number of words
    return 0;
}
