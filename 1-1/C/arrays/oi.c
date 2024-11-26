#include <stdio.h>

#define INIT_ARRAY(arr, value)\
do { \
        for(size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { \
            arr[i] = value; \
        } \
    } while(0)

int main() {
    int arr[10];
    INIT_ARRAY(arr, 5);

    // Printing the array to verify
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
