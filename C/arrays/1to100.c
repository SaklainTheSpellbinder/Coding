#include<stdio.h>
int main()
{
    int arr[8]={1,2,3,5,6,7,8,9};
    int temp=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<=9;j++){
        if(arr[i]==j)
        continue;
        else
        temp=1;
    }
    
    }
    return 0;
}