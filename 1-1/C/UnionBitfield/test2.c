#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
    union Data* b;
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i: %d\n", data.i);
    printf("data.f: %.2f\n", data.f);
    printf("data.str: %s\n", data.str);

    data.f = 5.5;
    printf("data.i: %d\n", data.i);
    printf("data.f: %.2f\n", data.f);
    printf("data.str: %s\n", data.str);

    sprintf(data.str, "Hello");
    printf("data.i: %d\n", data.i);
    printf("data.f: %.2f\n", data.f);
    printf("data.str: %s\n", data.str);

    printf("%d\n",sizeof(data));

    // Notice that previous values of `i` and `f` are overwritten.
    printf("data.i: %d\n", data.i);  // Undefined behavior
    printf("data.f: %.2f\n", data.f);  // Undefined behavior

    return 0;
}
