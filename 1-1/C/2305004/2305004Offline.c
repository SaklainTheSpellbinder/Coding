#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int brr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&brr[i]);
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        int tidx;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==brr[j])
                tidx=j;
        }
        for(int j=i+1;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(arr[j]==brr[k] && k>tidx)
                    count++;
            }
        }
    }
    printf("%d",count);
}