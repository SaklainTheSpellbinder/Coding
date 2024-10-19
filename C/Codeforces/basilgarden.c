#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int flag=0;
        int count=0;
        while(flag==0)
        {
            flag=1;
            for(int i=0;i<n-1;i++)
            {
                if(arr[i]>arr[i+1])
                {
                    arr[i]=arr[i]-1;
                }
                if(i+1==n-1)
                    arr[i+1]=arr[i+1]-1;
                if(arr[i]!=0)
                    flag=0;
            }
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}