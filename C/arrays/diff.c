#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[6]={1,3,5,7,9,11};
    int sumeven=0;
    int sumodd=0;
    for(int i=0;i<6;i++)
    {
        if(i%2==0)
        sumeven=sumeven+arr[i];
        else
        sumodd=sumodd+arr[i];
    }
   int diff=abs(sumodd-sumeven);
   printf("The difference is %d",diff);
   return 0;
}