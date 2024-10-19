#include<stdio.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int p=arr[0]+1;
        int temp=1;
        for(int j=0;j<n;j++)
        {
            
            if(p<=abs(arr[j]-arr[j+1]) && p<=abs(arr[j]-arr[j-1]))

        }
    }
}