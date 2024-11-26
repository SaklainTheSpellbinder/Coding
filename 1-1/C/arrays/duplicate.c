#include<stdio.h>
int main(){
    int arr[7]={1,2,1,3,4,3,6};
    for(int i=0;i<7;i++)
    {
        for(int j=i;j<7;j++)
        {
            if(i!=j && arr[i]==arr[j])
            {
                printf("Duplicate number: %d\n",arr[i]);
            }
        }
    }
    return 0;
}