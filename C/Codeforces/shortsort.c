#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t); // Read the number of test cases

   for(int i=1;i<=t;i++) {
        char s[4];
        scanf("%s", s); // Read the string for each test case

        // Check if the string can be converted to "abc" with at most one swap
        if (strcmp(s, "abc") == 0 || strcmp(s, "acb") == 0 || strcmp(s, "bac") == 0 || strcmp(s,"cba")==0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
