#include<stdio.h>
int main(){
    int arr[3][2]={
        {1,2},
        {4,5},
        {7,8}
    };
    int brr[2][4]={
        {2,3,4,3},
        {5,6,9,4},
    };
    int m=3;
    int q=4;
    int n=2;
    int p=2;
    if(n!=p)
    {
        printf("Syntax error");
    }
    else{
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<q;k++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum=sum+arr[i][j]*brr[j][k];
            }
            printf("%d ",sum);
        }
        printf("\n");
    }}
    return 0;
}