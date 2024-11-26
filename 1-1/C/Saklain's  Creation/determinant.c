#include <stdio.h>

void matrix(int arr[][10], int brr[][10], int i, int n) {
    int p, q, m, t;
    for (p = 1, t = 0; p < n; p++, t++) {
        for (q = 0, m = 0; q < n; q++) {
            if (q == i)
                continue;
            brr[t][m] = arr[p][q];
            m++;
        }
    }
}

int determinant(int arr[][10], int n) {
    if (n == 1)
        return arr[0][0];
    
    int brr[10][10];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        matrix(arr, brr, i, n);
        if (i % 2 == 0)
            sum += arr[0][i] * determinant(brr, n - 1);
        else
            sum -= arr[0][i] * determinant(brr, n - 1);
    }
    return sum;
}

int main() {
    int n;
    printf("Enter the size of the nXn matrix: ");
    scanf("%d", &n);
    int arr[10][10];
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("The entered matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int result = determinant(arr, n);
    printf("The determinant of the matrix is: %d\n", result);
    return 0;
}