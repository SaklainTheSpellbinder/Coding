#include<stdio.h>//pass by reference
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    return;
}

int main()
{
    int m,n;
    printf("Enter first number:");
    scanf("%d",&m);
    printf("\nEnter second number:");
    scanf("%d",&n);
    swap(&m,&n);
    printf("The value of first is %d\n",m);
    printf("The value of second is %d",n);
    return 0;
}