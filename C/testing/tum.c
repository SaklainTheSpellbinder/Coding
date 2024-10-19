#include<stdio.h>
int main(){
    int base,power;
    printf("Enter the base: ");
    scanf("%d",&base);
    printf("Enter the power: ");
    scanf("%d",&power);
    int a=base;
    for(int i=1;i<power;i++)
    {
        a=base*a;
    }
    if(power==0)
        printf("The ans is %d",1);
    else
        printf("The answer is %d",a);
    
    return 0;
}