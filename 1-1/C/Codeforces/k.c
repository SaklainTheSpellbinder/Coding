#include <stdio.h>
#include <stdbool.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int sum = 0;
        bool flag = false;
        while (flag == false) {
            int k = 0;
            for (int i = 1; i < n; i++) {
                if (arr[i - 1] > arr[i]) {
                    int diff = arr[i - 1] - arr[i];
                    arr[i] += diff;
                    k += diff;
                }
            }
            sum += k + 1;
            flag = true; // Assume the array is sorted, prove otherwise
            for (int i = 1; i < n; i++) {
                if (arr[i - 1] > arr[i]) {
                    flag = false;
                    break;
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
