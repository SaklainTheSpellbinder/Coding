#include <stdio.h>

// Function to determine if two intervals intersect
int do_strings_intersect(int a, int b, int c, int d) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (c > d) {
        int temp = c;
        c = d;
        d = temp;
    }
    return (a < c && c < b && b < d) || (c < a && a < d && d < b);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        if (do_strings_intersect(a, b, c, d)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
