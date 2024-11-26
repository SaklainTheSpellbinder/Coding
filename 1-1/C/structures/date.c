#include<stdio.h>
int main()
{
   struct date{
    int day;
    int month;
    int year;
   } a,b;
   a.day=12;
   a.month=6;
   a.year=2020;
   b=a;
   if(a.day==b.day && a.month==b.month && a.year==b.year)
   printf("Equal");
   else
   printf("Unequal");
   return 0;
}