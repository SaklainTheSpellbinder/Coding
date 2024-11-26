#include<stdio.h>
int main(){
    int arr[4][4]={
        {1,2,3,5},
        {4,5,6,6},
        {7,8,9,8},
        {4,7,6,4}
    };

    int n=4;

    printf("Before anything:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    printf("After reverse:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n/2);j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[i][n-1-j];
            arr[i][n-1-j]=temp;
        }
    }
    printf("After everything:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}