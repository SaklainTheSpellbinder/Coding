#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //char *str = (char *)malloc(10 * sizeof(char));  // Allocate space for 10 characters

    // if (str == NULL) {
    //     printf("Memory allocation failed!\n");
    //     return 1;
    // }

    char str[]= "bangladesh";  // ✅ Store "bangladesh" in dynamically allocated memory
    printf("Before modification: %s\n", str);

    str[11]="india";  // ✅ Correct way to change string
    printf("After modification: %s\n", str);

    //free(str);  // Free memory
    return 0;
}
