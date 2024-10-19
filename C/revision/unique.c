#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[7]={1,4,2,3,2,3,1};
    bool flag=false;
    int unique;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(arr[i]==arr[j] && i!=j)
            {
                flag=false;
                break;
            }
            else if(arr[i]!=arr[j])
            {
                flag=true;
            }
        }
        if(flag==true)
        {
            unique=arr[i];
            break;
        }
    }
    if(flag==true)
    {
        printf("Unique is %d\n",unique);
    }
    return 0;
}