// #include<stdio.h>
// #include<math.h>
// int main(){
//     printf("%d",(int)round(-2.5));
// }
// #include <stdio.h>

// int main() {
//     printf("Compiler version: %ld\n", __STDC_VERSION__);
//     return 0;
// }
#include <stdio.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON

int main() {
    printf("Current rounding mode: %d\n", fegetround());
    return 0;
}
