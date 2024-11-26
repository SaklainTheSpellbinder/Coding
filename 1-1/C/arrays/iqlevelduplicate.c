#include<stdio.h>
#include<string.h>
int main(){
    int arr[11]={6,1,7,3,2,5,4,8,9,9,10};
    int n=10;
    int brr[n+1];
    int temp=0;
    memset(brr,0,sizeof(brr));
    for(int i=0;i<=n;i++)
    {
        int x=arr[i];
        if(brr[x]==0)
        {
            brr[x]=1;
        }
        else
        {
            printf("Duplicate is %d",x);
            temp=1;
            break;
        }
        if(temp==1)
        break;
    }
    return 0;
}