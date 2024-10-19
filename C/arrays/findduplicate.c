#include<stdio.h>
int main(){
    int arr[11]={6,1,7,3,2,5,4,8,9,9,10};
    int temp=0;
    for(int i=0;i<11;i++)
    {
        for(int j=i+1;j<11;j++)
        {
            if(arr[i]==arr[j])
            {
                printf("Duplicate is %d",arr[i]);
                temp=1;
                break;
            }
        }
        if(temp==1)
        {
            break;
        }
    }
    return 0;
}