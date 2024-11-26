#include<stdio.h>

void fun(int n)
{
    if(n>1)
        fun(n-1);
    if(n%2==0)
    {
        printf("%d ",n-1);
        return;
    }
    else if(n%2!=0)
    {
        printf("%d  ",n+1);
        return;
    }
}

int main()
{
    fun(10);
    return 0;
}