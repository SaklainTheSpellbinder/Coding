#include<stdio.h>
int main(){
    float a;
    printf("Enter the number: ");
    scanf("%f",&a);
    int b=a;
    printf("The fractional part is %f",a-b);
    return 0;
}