#include<stdio.h>
int main(){
    int x1,y1,x2,y2,x3,y3;
    printf("Enter the first point:");
    scanf("%d%d",&x1,&y1);
    printf("Enter the second point:");
    scanf("%d%d",&x2,&y2);
    printf("Enter the third point:");
    scanf("%d%d",&x3,&y3);
    int arr[3][3]={
        {x1,y1,1},
        {x2,y2,1},
        {x3,y3,1}
    };
    int sum=arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])-arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0])+arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
    printf("The area is %d",sum/2);
    return 0;
}