#include<stdio.h>
int main(){
    float n;
    scanf("%f",&n);
    int intN=(int)n;
    int ceiL;
    if(n>intN)
    {
        ceiL=intN+1;
    }
    else
        ceiL=intN;
    printf("The ceil value is %d",ceiL);
    return 0;
}