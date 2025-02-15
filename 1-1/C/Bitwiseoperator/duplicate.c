// #include <stdio.h>

// int findDuplicate(int arr[], int n) {
//     int xorArr = 0, xorExpected = 0;

//     // XOR all elements in the array
//     for (int i = 0; i < n; i++) {
//         xorArr ^= arr[i];
//     }

//     // XOR numbers from 1 to n-1 (since one number is repeated)
//     for (int i = 1; i < n; i++) {
//         xorExpected ^= i;
//     }

//     // The duplicate number is found by XORing these two results
//     return xorArr ^ xorExpected;
// }

// int main() {
//     int arr[] = {1, 3, 4, 2, 5, 3};  // Duplicate number: 3
//     int n = sizeof(arr) / sizeof(arr[0]);

//     printf("Duplicate number: %d\n", findDuplicate(arr, n));
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

void findDuplicates(int arr[], int n) {
    int *hashTable = (int *)calloc(100000, sizeof(int)); // Adjust size as needed
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (hashTable[arr[i] + 50000]) { // Shift to avoid negative indexing
            printf("Duplicate found: %d\n", arr[i]);
            found = 1;
        } else {
            hashTable[arr[i] + 50000] = 1;
        }
    }

    if (!found)
        printf("No duplicate found.\n");

    free(hashTable);
}

int main() {
    int arr1[] = {10, 20, 30, 40, 20};  // Contains duplicate: 20
    int arr2[] = {-5, 10, 15, 20};  // No duplicate
    int arr3[] = {100000, -99999, 500, -99999};  // Contains duplicate: -99999

    printf("Test Case 1:\n");
    findDuplicates(arr1, sizeof(arr1) / sizeof(arr1[0]));

    printf("Test Case 2:\n");
    findDuplicates(arr2, sizeof(arr2) / sizeof(arr2[0]));

    printf("Test Case 3:\n");
    findDuplicates(arr3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}

