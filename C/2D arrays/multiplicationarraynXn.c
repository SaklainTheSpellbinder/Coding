#include<stdio.h>
int main(){
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int brr[3][3]={
        {2,3,4},
        {5,6,9},
        {1,2,3}
    };
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            int sum=0;
            for(int j=0;j<3;j++)
            {
                sum=sum+arr[i][j]*brr[j][k];
            }
            printf("%d ",sum);
        }
        printf("\n");
    }
    return 0;
}