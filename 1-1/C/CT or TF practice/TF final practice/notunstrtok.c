#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello world";
    char str2[] = "This is C";
    char *token1, *token2;
    char *saveptr1 = NULL, *saveptr2 = NULL;

    token1 = strtok_s(str1, " ", &saveptr1);
    token2 = strtok_s(str2, " ", &saveptr2);

    printf("First tokens: %s, %s\n", token1, token2);
    return 0;
}
