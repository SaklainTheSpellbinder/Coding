#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int x,y;
    char ch;
    for(int i=1;i<=t;i++)
    {
        scanf("%d%c%d",&x,&ch,&y);\


      if(x>y)
            printf("%d %d\n",y,x);
        else
            printf("%d %d\n",x,y);

    }
    return 0;
}
