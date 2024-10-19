#include<stdio.h>
int main()
{
    int arr[8]={1,2,3,4,5,6,7,8};
    int max=arr[0];
    for(int i=0;i<8;i++)
    {
        if(max<arr[i])
        max=arr[i];
    }
    int m=max-1;
    int temp=0;
    for(int j=0;j>-1;j++)
    {
       for(int k=0;k<8;k++)
       {
        if(m==arr[k])
        {
            m=arr[k];
            temp=1;
            break;
        }
       }
       if(temp==1)
       break;
       else
       m--;
    }
    printf("The second largest is: %d",m);
    return 0; 
}