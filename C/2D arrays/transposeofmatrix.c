#include<stdio.h>
int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,6,5,1}};
    int brr[4][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            brr[j][i]=arr[i][j];
        }
    }
     for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",brr[i][j]);
        }
        printf("\n");
    }
   return 0;
}