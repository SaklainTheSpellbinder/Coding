#include<stdio.h>
#include<stdlib.h>  // For dynamic memory allocation

int main() {
    int t;
    scanf("%d", &t);  // Read the number of test cases

    while (t--) {  // Loop through each test case
        int n;
        scanf("%d", &n);  // Read the size of the array

        int *arr = (int *)malloc(n * sizeof(int));  // Allocate memory for the array
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);  // Read elements of the array
        }

        int flag = 0;
        int count = 0;

        while (flag == 0) {  // Outer loop to modify the array until flag is 1
            flag = 1;
            for (int i = 1; i < n; i++) {  // Inner loop to traverse the array
                if (arr[i - 1] > arr[i] || i - 1 == n - 2) {  // Condition for decrement
                    arr[i - 1]--;
                }
                if (arr[i - 1] != 0) {  // Check if further modifications are needed
                    flag = 0;  // Reset flag if modification is required
                }
            }
            count++;  // Increment count after each modification loop
        }

        printf("%d\n", count);  // Output the count of modifications

        free(arr);  // Free dynamically allocated memory
    }

    return 0;
}
