#include<stdio.h>

int matrix(int arr[][],int i,int n)
{
    int brr[n][n];
    for(int p=0;p<n;p++)
    {
        int m=0;
        for(int q=0;q<n;q++)
        {
            if(m==i)
                m++;
            brr[p][q]=arr[p+1][m];
            m++;
        }
    }
    return brr;
}

int determinant(int arr[][],int n)
{
    if(n==1)
        return arr[0][0];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            sum=sum+arr[0][i]*determinant(matrix(arr,i,n-1),n-1);
        else
            sum=sum-arr[0][i]*determinant(matrix(arr,i,n-1),n-1);
    }
    return sum;
}

int main(){
    int n;
    printf("Enter the n of nXn matrix: ");
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int result=determinant(arr,n);
    printf("The determinant of the matrix is: %d",result);
    return 0;
}