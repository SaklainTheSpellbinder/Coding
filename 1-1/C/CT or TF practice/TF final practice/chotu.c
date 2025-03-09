#include<stdio.h>

void reverseWord(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "       Hello                   aami saklain          ";
    int len = 0;
    
    // Calculate the length of the string
    while (str[len] != '\0') len++;

    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            // Reverse each word
            if (i > start) {
                reverseWord(str, start, i - 1);
            }
            // Move start to the next word
            start = i + 1;
        }
    }

    printf("%s", str);
    return 0;
}
