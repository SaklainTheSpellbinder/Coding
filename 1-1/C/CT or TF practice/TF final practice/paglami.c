#include <stdio.h>

struct Data {
    int x;
};

int main() {
    struct Data d1 = {10};
    struct Data d2 = d1;  // Copying d1 into d2

    printf("Before change:\n");
    printf("d1.x = %d, d2.x = %d\n", d1.x, d2.x);

    d1.x = 20;  // Changing d1

    printf("After change:\n");
    printf("d1.x = %d, d2.x = %d\n", d1.x, d2.x);  // d2.x remains unchanged

    return 0;
}
