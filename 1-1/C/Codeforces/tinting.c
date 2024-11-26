#include<stdio.h>

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

        int flag = 0;
        int count = 0;

        while (flag == 0) {  
            flag = 1;
            for (int i = 0; i < n - 1; i++) {  
                if (arr[i] > arr[i + 1]) {  
                    arr[i]--;
                    flag = 0;  
                }
            }
            if (arr[n - 1] != 0) {  
                arr[n - 1]--;
                flag = 0;  
            }
            count++;  
        }

        printf("%d\n", count-1);  
    }

    return 0;
}
