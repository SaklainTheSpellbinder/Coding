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

        long long sum = 0;
        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                int difference = arr[i - 1] - arr[i];
                arr[i] += difference;  // Make the current element equal to the previous one
                sum += difference + 1; // Add the cost of the increments
                sorted = false;
            }
        }

        printf("%lld\n", sum);
    }
    return 0;
}
