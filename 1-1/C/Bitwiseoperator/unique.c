// int uniquenumber(int arr[],int n){
//     int unique=arr[0];
//     for(int i=1;i<n;i++){
//         unique^=arr[i];
//     }
//     return unique;
// }


// #include <stdio.h>

// int uniquenumber(int arr[], int n) {
//     int unique = arr[0];
//     for (int i = 1; i < n; i++) {
//         unique ^= arr[i];  // XOR all elements
//     }
//     return unique;
// }

// int main() {
//     int arr[] = {1, 90, 89, 90, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     printf("Unique number: %d\n", uniquenumber(arr, n));
//     return 0;
// }

#include <stdio.h>

void findTwoUniqueNumbers(int arr[], int n, int *num1, int *num2) {
    int xor_all = 0;
    for (int i = 0; i < n; i++) {
        xor_all ^= arr[i];  // XOR all elements
    }

    // Find rightmost set bit (bit that differs between num1 and num2)
    int set_bit = xor_all & -xor_all;  // Extract rightmost 1-bit

    *num1 = 0, *num2 = 0;
    
    // Divide numbers into two groups based on the set bit
    for (int i = 0; i < n; i++) {
        if (arr[i] & set_bit)
            *num1 ^= arr[i];  // First unique number
        else
            *num2 ^= arr[i];  // Second unique number
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 1, 4};  // Unique numbers: 3 and 4
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int num1, num2;
    findTwoUniqueNumbers(arr, n, &num1, &num2);
    
    printf("Two unique numbers: %d and %d\n", num1, num2);
    return 0;
}

