#include <stdio.h>

union FloatToInt {
    float f;
    unsigned int i;
};

int main() {
    union FloatToInt data;
    data.f = 3.14;
    //data.i=3339393939;
    printf("Float: %.2f\n", data.f);
    printf("Interpreted as Integer: %u\n", data.i);

    return 0;
}
