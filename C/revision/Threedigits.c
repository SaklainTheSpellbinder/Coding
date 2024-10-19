#include<stdio.h>
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    if(n>99 && n<1000)
        printf("Three digits");
    else
        printf("Not three digits");
    return 0;
}