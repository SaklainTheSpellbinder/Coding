#include<stdio.h>
int main()
{
    int marks[10]={95,90,31,25,100,50,65,89,97,33};
    for(int i=0;i<=9;i++)
    {
        if(marks[i]<35)
        printf("Roll number:%d\n",i);
    }
    return 0;
}