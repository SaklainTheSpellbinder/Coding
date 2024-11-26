#include<stdio.h>
int main()
{
    int arr[8]={7,6,5,4,11,13,9};
    for(int i=0;i<8;i++)
    {
        if(i%2==0)
        arr[i]=arr[i]+10;
        else
        arr[i]=2*arr[i];
    }
    for(int j=0;j<8;j++)
    {
       printf("%d\n",arr[j]);
    }
    return 0;
}