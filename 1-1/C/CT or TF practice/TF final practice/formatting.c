#include <stdio.h>
int main() {
    int num = 15;
    // printf("%#o\n", num);   // ✅ Octal (0 prefix) → Output: 017
    // printf("%#x\n", num);   // ✅ Hex (0x prefix) → Output: 0xf
    // printf("%#X\n", num);   // ✅ Hex (0X prefix) → Output: 0X
    printf("%#7o\n", 15);   // ✅ Correct: Octal with minimum width 7
printf("%#7x\n", 15);   // ✅ Correct: Hexadecimal with minimum width 7
printf("%f\n", 15.0); // ✅ Correct: Float with decimal point, min width 7
    return 0;
}
// #include <stdio.h>
// int main() {
//     double num = 12.0;
//     printf("%#f\n", num);   // ✅ Forces decimal point → Output: 12.000000
//     printf("%#g\n", num);   // ✅ Forces decimal point → Output: 12.0000
//     return 0;
// }

