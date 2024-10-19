#include<stdio.h>
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    if(y>=0)
    {
        while(y)
        {
            x++;
            y--;
        }
    }
    else
    {
        while(y)
        {
            x--;
            y++;
        }
    }
    printf("The sum :%d",x);
    return 0;
}