#include<stdio.h>
int main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int nums[n];
    int t=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]==nums[j])
            {
                printf("true");
                t=1;
                break;
            }
        }
    }
    if(t==0)
    {
        printf("false");
    }
    return 0;
}