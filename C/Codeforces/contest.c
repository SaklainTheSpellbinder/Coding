#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    for(int j=1;j<=n;j++)
    {
        int sum=0;
        for(int i=0;i<3;i++)
        {
            int arr[3];
            scanf("%d",&arr[i]);
            sum=sum+arr[i];
        }
        if(sum>=2)
        {
            count++;
        }       
    }
    printf("%d",count);
    return 0;
}