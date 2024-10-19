#include <stdio.h>

int main() {
    int arr[10];

    // Total size in bytes
    int size_in_bytes = sizeof(arr);

    // Size of each element in the array
    size_t element_size = sizeof(arr[0]);

    // Number of elements in the array
    size_t num_elements = size_in_bytes / element_size;

    printf("Total size in bytes: %d\n", size_in_bytes);
    printf("Size of each element: %zu\n", element_size);
    printf("Number of elements: %zu\n", num_elements);

    return 0;
}
