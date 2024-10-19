#include<stdio.h>
int main()
{ int x1,x2,x3,y1,y2,y3;
scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
float m1=(y2-y1)/(x2-x1);
float m2=(y3-y2)/(x3-x2);
if(m1==m2)
printf("On one straight line");
else
printf("not on one straight line");




}
