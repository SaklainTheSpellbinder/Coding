#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the base: ");
    scanf("%d",&a);
    printf("Enter the power: ");
    scanf("%d",&b);
    if(b>=0)
    {
        int mp=1;
        for(int i=1;i<=b;i++)
        {
            mp=mp*a;
        }
        printf("The answer is %d",mp);
    }
    else
    {
        double mp=1.0000000000;
        for(int i=1;i<=-b;i++)
        {
            mp=mp/a;
        }
        printf("The answer is %.15lf",mp);
    }
}