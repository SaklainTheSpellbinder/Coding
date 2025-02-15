#include <stdio.h>

#define cube(a) a * a * a
#define swap(t, x, y) t=x; x=y; y=t;
#define max(x, y) x > y ? x : y;

int main() {
    int a = 10, b = 20;
    int t = 0;
    
    if (a > b) swap(t, a, b);  // Since 10 is not greater than 20, swap is not executed.
    
    printf("%d %d\n", a, b);   // Output: 10 20

    // int c = cube(b + 2);       // cube(20 + 2) → 20 + 2 * 20 + 2 * 20 + 2 = 20 + 40 + 2 = 22 * 22 * 22 (incorrect macro expansion!)
    // printf("%d\n", c);         // Incorrect due to missing parentheses in macro: cube(22) expands as 22 * 22 * 22 = **10648**
    
    // int max_val = max(a++, b++);  // max(10++, 20++)
    // // Due to macro expansion:
    // // max(a++, b++) → a++ > b++ ? a++ : b++
    // // Post-increments apply after the comparison.
    // // The comparison is 10 > 20 (false), so b++ (20) is chosen.
    // // After this line: a = 11, b = 21, max_val = 20
    
    // printf("%d %d %d\n", a, b, max_val);  // Expected Output: 11 21 20

    return 0;
}
