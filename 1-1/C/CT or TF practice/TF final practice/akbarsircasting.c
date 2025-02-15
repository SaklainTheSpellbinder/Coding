#include<stdio.h>
int main(){
    int x=13,y=5;
    printf("%g %g", x / y, 1.0 * x / y);
    printf("%g %g %g",(float)x/y,x/(float)y,(float)x/(float)y);

}