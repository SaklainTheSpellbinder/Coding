#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[] = " Saklain"; // Use a writable array for the first string
    char y[] = "Hasan"; // Use a writable array for the second string
    
    // Calculate the length of the concatenated string
    int total_length = strlen(str) + strlen(y) + 1; // +1 for the null terminator
    
    // Allocate memory for the concatenated string
    char* result = (char*)malloc(total_length * sizeof(char));
    
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }
    
    // Copy y to the result
    strcpy(result, y);
    
    // Concatenate str to the result
    strcat(result, str);
    
    // Print the concatenated result
    printf("%s\n", result);
    
    // Free the allocated memory
    free(result);
    
    return 0;
}
