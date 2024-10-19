#include<stdio.h>
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    return;
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<3;i++)
    {
        for(int j=i+1;j<3;j++)
        {
            swap(&arr[i][j],&arr[j][i]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}