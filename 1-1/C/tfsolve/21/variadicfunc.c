#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int getTotalSum(int n, char *fmt, ...) {
    int m = strlen(fmt);
    int count = n * m;

    va_list arg;
    va_start(arg, fmt);  

    int sum = 0;

    for (int i = 1; i <= n; i++) {  
        for (int j = 0; j < m; j++) {
            if (fmt[j] == 's') {
                char* str=va_arg(arg, char*);
                int size = strlen(str);  
                for (int k = 0; k < size; k++) {
                    sum += (int)str[k];  
                }
            } else if (fmt[j] == 'i') {
                sum += va_arg(arg, int);
            } else if (fmt[j] == 'c') {
                sum += va_arg(arg, int);  
            }
        }
    }

    va_end(arg);
    return sum;
}

int main() {
    int total_sum = getTotalSum(2, "sicc", "I am confident", 2, 'p', 'a', "I will pass", 3, 'p', 'b');
    printf("%d\n", total_sum);  

    total_sum = getTotalSum(2, "ic", 10, 'A', 20, 'a');
    printf("%d\n", total_sum);  

    return 0;
}
