#include<stdio.h>
int maze(int a,int b)
{ 
    int downways=0;
    int rightways =0;

    
    if(a==1 && b==1)
return 1;
if(a==1){
//cannot go down
rightways+=maze(a,b-1);}
if(b==1)
{downways+=maze(a-1,b);

}
if(a>1 && b>1){
   rightways+=maze(a,b-1);
   downways+=maze(a-1,b);}
   
   int totalways=rightways+downways;
   return totalways;
   }


int main()
{
    int n,m;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    printf("Enter the number of columns:");
    scanf("%d",&m);
    printf("The number of ways is:%d",maze(n,m));
}