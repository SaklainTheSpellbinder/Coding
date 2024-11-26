#include<stdio.h>
int main(){
    int arr[11]={6,1,7,3,2,5,4,8,9,9,10};
    int n=10;
    int sum=0;
    int sumarray=0;
    for(int i=0,j=1;i<=n;i++,j++)
    {
        sum=sum+j;
        sumarray=sumarray+arr[i];
    }
    int x=sumarray-sum+n+1;
    printf("Duplicate is %d",x);
    return 0;
}