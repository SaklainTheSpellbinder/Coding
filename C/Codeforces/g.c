#include <stdio.h>
#include <string.h>

int main() {
    char ch[100];  // Increased size to handle longer strings safely
    char bh[100];  // Increased size to handle longer strings safely
    int n;

    printf("Enter the number of string pairs: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Enter pair %d: ", i);
        scanf("%s %s", ch, bh);
    }

    // Ensure there is a second character in the last string read
    if (strlen(ch) > 1) {
        printf("Second character of the last string in ch: %c\n", ch[1]);
    } else {
        printf("The last string in ch is too short to have a second character.\n");
    }

    return 0;
}
