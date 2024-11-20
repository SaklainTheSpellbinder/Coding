#include <stdio.h>
#include <string.h>

void reverse_words(char sentence[]) {
    int len = strlen(sentence);
    char reversed[1000]; // Array to store the reversed sentence
    int start = 0, end = 0, k = 0;

    // Start from the end of the sentence
    for (int i = len - 1; i >= 0; i--) {
        if (sentence[i] == ' ' || i == 0) {
            start = (i == 0) ? i : i + 1; // Adjust start position for the first word
            end = len - 1;
            // Copy the word into the reversed array
            for (int j = start; sentence[j] != ' ' && sentence[j] != '\0'; j++) {
                reversed[k++] = sentence[j];
            }
            if (i != 0) {
                reversed[k++] = ' '; // Add space between words
            }
        }
    }
    reversed[k] = '\0'; // Null-terminate the reversed string
    printf("%s\n", reversed);
}

int main() {
    char sentence[] = "Saklain Loves Arana";
    reverse_words(sentence);
    return 0;
}
