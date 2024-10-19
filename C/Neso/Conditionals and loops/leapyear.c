#include<stdio.h>
int main()
{
    int n;
    printf("Enter a year: ");
    scanf("%d",&n);
    if(n%4==0)
    {
        if(n%100==0 && n%400!=0)
        {
            printf("Not leap Year");
        }
        else
            printf("Leap Year");
    }
    else
        printf("Not leap year");
    return 0;
}