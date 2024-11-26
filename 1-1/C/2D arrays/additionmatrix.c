#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter number of rows:");
    scanf("%d",&r);
    printf("Enter number of columns:");
    scanf("%d",&c);
    int arr[r][c],brr[r][c];
    printf("Enter first matrix:");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        scanf("%d",&arr[i][j]);
    }
    printf("Enter second matrix:");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        scanf("%d",&brr[i][j]);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        printf("%d ",arr[i][j]+brr[i][j]);
        printf("\n");
    }
    return 0;
}