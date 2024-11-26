#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a,b,c;
    a=n%10;
    n=n/10;
    b=n%10;
    n=n/10;
    c=n%10;
    int min;
    if(a<b && a<c)
    {
        min=a;
    }
    else if(b<c)
    {
        min=b;
    }
    else{
        min=c;
    }
    printf("The min digit is: %d",min);
    return 0;
}