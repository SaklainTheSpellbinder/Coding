#include<stdio.h>
int main()
{
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    for(int i=0;i<3;i++)
    {
        if(i%2!=0)
        {
            for(int j=2;j>=0;j--)
            {
                printf("%d ",arr[i][j]);
            }
        }
        else
        {
            for(int k=0;k<3;k++)
            {
                printf("%d ",arr[i][k]);
            }
        }
        printf("\n");
    }
    return 0;
}