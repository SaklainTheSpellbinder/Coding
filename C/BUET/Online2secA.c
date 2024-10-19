#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int missing=0,repeating=0;
    for(int i=1;i<=n;i++)
    {
        int temp=0;
        for(int j=0;j<n;j++)
        {
            if(i==arr[j])
            {
                temp++;
            }
        }
        if(temp==0)
        {
            missing=i;
        }
        else if(temp>1)
            repeating=i;
    }
    printf("Missing=%d\nRepeating=%d",missing,repeating);
    return 0;
}