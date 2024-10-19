#include <stdio.h>
#include <string.h>

void solve(int t, char test_cases[][11]) {
    for (int i = 0; i < t; i++) {
        char *s = test_cases[i];
        int len = strlen(s);
        
        // Check if all characters are the same
        int same_char = 1;
        for (int j = 1; j < len; j++) {
            if (s[j] != s[0]) {
                same_char = 0;
                break;
            }
        }
        
        if (same_char) {
            printf("NO\n");
        } else {
            printf("YES\n");
            // Sort the string
            for (int j = 0; j < len - 1; j++) {
                for (int k = j + 1; k < len; k++) {
                    if (s[j] > s[k]) {
                        char temp = s[j];
                        s[j] = s[k];
                        s[k] = temp;
                    }
                }
            }
            printf("%s\n", s);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    char test_cases[t][11]; // Assuming maximum length of 10 + 1 for the null terminator
    
    for (int i = 0; i < t; i++) {
        scanf("%s", test_cases[i]);
    }
    
    solve(t, test_cases);
    
    return 0;
}
