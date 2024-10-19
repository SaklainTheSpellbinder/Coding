#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr[7] = {1, 1, 2, 4, 3, 2, 4};
   
    for (int i = 0; i < 7; i++) {
        bool temp = false;
        for (int j = 0; j < 7; j++) {
            if (i != j && arr[i] == arr[j]) {
                temp = true;
                break;
            }
        }
        if (temp==false) {
            printf("Unique is %d\n", arr[i]);
            break;
        }
    }
    return 0;
}

