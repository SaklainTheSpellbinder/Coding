#include <stdio.h>

int main() {
    char str[] = "aaabbcddd";
    char result[100];
    char temp = str[0];
    int count = 1;
    int i = 1, k = 0;

    while (str[i] != '\0') {
        if (str[i] == temp) {
            count++;
        } else {
            result[k++] = temp;
            // if (count < 10) {
            //     result[k++] = count + '0'; // Single-digit counts
            // } else {
            //     // Convert count to multiple characters
            //     int digits[10], d = 0;
            //     while (count > 0) {
            //         digits[d++] = count % 10;
            //         count /= 10;
            //     }
            //     for (int j = d - 1; j >= 0; j--) {
            //         result[k++] = digits[j] + '0';
            //     }
            // }
            temp = str[i];
            count = 1; // Reset count for the new character
        }
        i++;
    }
    // Add the last group
    result[k++] = temp;
    // if (count < 10) {
    //     result[k++] = count + '0';
    // } else {
    //     int digits[10], d = 0;
    //     while (count > 0) {
    //         digits[d++] = count % 10;
    //         count /= 10;
    //     }
    //     for (int j = d - 1; j >= 0; j--) {
    //         result[k++] = digits[j] + '0';
    //     }
    // }
    result[k] = '\0'; // Null-terminate the result string

    printf("%s\n", result);
    return 0;
}
