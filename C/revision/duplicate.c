#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[7]={1,2,1,3,4,3,6};
    bool flag=false;
    for(int i=0;i<7;i++)
    {
        for(int j=i+1;j<7;j++)
        {
            if(arr[i]==arr[j])
            {
                printf("Duplicate is %d\n",arr[i]);
            }
        }
    }
    if(flag)
        printf("Kutta");
    return 0;
}