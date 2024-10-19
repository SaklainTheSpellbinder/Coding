#include<stdio.h>
int main()
{
    int i=1,p,n,countodd=0,counteven=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n!=0)
    {
        p=n%10;
        n=n/10;
        if(i%2==0)
            counteven=counteven+p;
        else
            countodd=countodd+p;
        i=i+1;
    }
    printf("Sum of odd:%d and Sum of even:%d",countodd,counteven);

}
