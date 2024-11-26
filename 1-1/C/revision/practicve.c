#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2) {
                break; // This break only exits the inner loop.
            }
            printf("i = %d, j = %d\n", i, j);
        }
    }
    return 0;
}