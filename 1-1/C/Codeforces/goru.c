#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();  // Consume the newline character after reading t
    
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d%d", &n, &m);
        getchar();  // Consume the newline character after reading n and m

        char arr[n][m];
        
        // Reading the 2D array
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                arr[j][k] = getchar();
            }
            getchar();  // Consume the newline character at the end of each row
        }
        
        int row = -1, column = -1;
        
        // Finding the last '#'
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[j][k] == '#') {
                    row = j + 1;
                    column = k + 1;
                }
            }
        }
        
        printf("%d %d\n", row, column);  // Print the result for each test case on a new line
    }
    
    return 0;
}
