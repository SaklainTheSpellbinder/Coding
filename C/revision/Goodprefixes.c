#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        long long sum = 0;
        int maxVal = arr[0];
        int count = 0;
        
        for (int p = 0; p < n; p++) {
            if (arr[p] > maxVal) {
                maxVal = arr[p];
            }
            sum += arr[p];
            if (sum == 2 * maxVal) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
