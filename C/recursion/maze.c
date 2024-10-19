#include<stdio.h>
int maze(int cr,int cc,int er,int ec)
{int rightways=0;
int downways=0;
if(cr==er && cc==ec)
return 1;
else if(cr==er)//only rightways call
{
    rightways +=maze(cr,cc+1,er,ec);
}
else if(cc==ec)//only downways call
{
    downways +=maze(cr+1,cc,er,ec);
}
else{
  rightways+=maze(cr,cc+1,er,ec);
     downways+=maze(cr+1,cc,er,ec);
}
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
    printf("The number of ways is %d",maze(1,1,n,m));
    return 0;
}