#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world! This;is:an-example";
    char *token = strtok(str, " ,;:-!");  // Multiple delimiters

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ,;:-!");
    }
    return 0;
}
