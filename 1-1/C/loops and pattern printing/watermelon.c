#include<stdio.h>
int main()
{
    int w;
    printf("weight of watermelon(Should be in 1 to 100):");
    scanf("%d",&w);
    if(w%2!=0 || w==2)
        printf("NO");
    else
        printf("YES");
   return 0;
}
