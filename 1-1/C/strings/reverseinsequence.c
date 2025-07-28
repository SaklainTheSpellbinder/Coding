#include <stdio.h>
#include <string.h>

void reverse_words(char sentence[]) {
    int len = strlen(sentence);
    char reversed[1000];
    int start = 0, end = 0, k = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (sentence[i] == ' ' || i == 0) {
            start = (i == 0) ? i : i + 1;
            end = len - 1;
            for (int j = start; sentence[j] != ' ' && sentence[j] != '\0'; j++) {
                reversed[k++] = sentence[j];
            }
            if (i != 0) {
                reversed[k++] = ' ';
            }
        }
    }
    reversed[k] = '\0';
    printf("%s\n", reversed);
}

int main() {
    char sentence[] = "Saklain Loves tintin";
    reverse_words(sentence);
    return 0;
}
