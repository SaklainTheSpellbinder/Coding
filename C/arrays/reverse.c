#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5};
    int reverse[5];
    for(int i=0;i<5;i++)
    {
        reverse[i]=arr[4-i];
    }
    for(int j=0;j<5;j++)
    {
        printf("%d ,",reverse[j]);
    }
    return 0;
}