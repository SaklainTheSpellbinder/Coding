#include<stdio.h>
int main(){
    int arr[3][4]={1,2,3,4,5,6,7,1,4,5,6,8};
    int maxSum=0;
    int row=0;
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for(int j=0;j<4;j++)
        {sum=sum+arr[i][j];}
        if(sum>maxSum)
        {
            maxSum=sum;
            row=i;
        }
    }
    printf("Row Number:%d\n",row);
    printf("Max Sum:%d",maxSum);
    return 0;
}