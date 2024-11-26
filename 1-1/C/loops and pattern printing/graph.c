#include<stdio.h>
int main()
{
float a,b;
printf("Enter the point:(");
scanf("%f",&a);
printf(",");
scanf("%f",&b);
printf(")\n");
if(a==0.00 && b==0.000)
printf("At the origin");
else if(a==0.00)
printf("On the Y axis");
else if(b==0.00)
printf("On the X axis");
else
printf("A general point");


}
