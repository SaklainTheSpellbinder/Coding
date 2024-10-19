#include<stdio.h>
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    return;
}
int main(){
    int arr[4][4]={{1,2,3,4},{4,5,6,6},{7,8,9,4},{1,2,3,5}};
    for(int i=0;i<4;i++)//transpose first
    {
        for(int j=i+1;j<4;j++)
        {
            swap(&arr[i][j],&arr[j][i]);
        }
    }
    for(int i=0;i<4;i++)//reverse the rows
    {
        for(int j=0;j<2;j++)
        swap(&arr[i][j],&arr[i][3-j]);
    }
    for(int i=0;i<4;i++)//printing
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}