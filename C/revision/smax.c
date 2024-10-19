#include<stdio.h>
#include<limits.h>
int main(){
    int arr[8]={8,1,3,4,5,6,6,8};
    int max=INT_MIN;
    int smax=INT_MIN;
    for(int i=0;i<8;i++)
    {
        if(max<arr[i])
        {
            smax=max;
            max=arr[i];
        }
        else if(smax<arr[i] && arr[i]!=max)
        {
            smax=arr[i];
        }
    }
    printf("The second largest is : %d",smax);
    return 0;
}