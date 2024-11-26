#include<stdio.h>
/* if we use two variables in made func:
void sum(int n,int s)
{
    if(n==0)
    {
        printf("%d",s);
        return 0;
    }
    sum(n-1,s+n);
    return;
}
*/
void sum(int x,int y,int z) //if we use three variables in made func
{
    y=y+1;
    if(y<=z)
    sum(x+y,y,z);
    else{
        printf("%d",x);
        return;
    }
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    sum(0,0,a);
    return 0;
}