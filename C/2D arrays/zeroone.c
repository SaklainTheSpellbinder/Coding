#include<stdio.h>
int main(){
    int arr[4][5]={{0,0,1,0,1},{1,0,0,0,1},{1,0,1,0,1},{0,1,0,1,0}};
      int maxSum=0;
    int row=0;
    for(int i=0;i<4;i++)
    {
        int sum=0;
        for(int j=0;j<5;j++)
        {sum=sum+arr[i][j];}
        if(sum>maxSum)
        {
            maxSum=sum;
            row=i;
        }
    }
    printf("Row Number:%d\n",row);
    printf("Max Count:%d",maxSum);
    return 0;
}