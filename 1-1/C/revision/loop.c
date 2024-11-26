#include<stdio.h>
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int temp=0;
    for(int i=2;i<=(n/2);i++)
    {
        if(n%i==0)
        {
            temp=1;
            break;
        }
    }
    if((temp==0 || n==2) && n!=1)
    {
        printf("Prime");
    }
    else if(n==1)
    {
        printf("Tejpata");
    }
    else
        printf("Non Prime");
    return 0; 
}