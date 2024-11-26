#include<stdio.h>

void fun(int arr[],int len,int* max,int* min)
{
    *max=arr[0];
    *min=arr[0];
    for(int i=0;i<len;i++)
    {
        if(arr[i]<*min)
            *min=arr[i];
        if(arr[i]>*max)
            *max=arr[i];
    }
    return;
}

int main(){
    int a[]={5,42,18,96,2,31,21,47,98,100,1};
    int len=sizeof(a)/sizeof(a[0]);
    int max,min;
    fun(a,len,&max,&min);
    printf("The max element is %d\nThe min element is %d",max,min);
    return 0;
}