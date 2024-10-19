#include<stdio.h>
int main(){
    int arr[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("Row total: ");
    for(int i=0;i<5;i++)
    {
        int row=0;
        for(int j=0;j<5;j++)
        {
            row+=arr[i][j];
        }
        printf("%d ",row);
    }
    printf("\nColumn total: ");
    for(int i=0;i<5;i++)
    {
        int col=0;
        for(int j=0;j<5;j++)
        {
            col+=arr[j][i];
        }
        printf("%d ",col);
    }
    return 0;
}