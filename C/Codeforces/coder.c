#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n%2==0)
        printf("%d\n",n*n/2);
    else
        {
            int h=n/2;
            int p=(h+1)*(h+1)+h*h;
            printf("%d\n",p);
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if((i+j)%2==0)
            printf("C");
           else
            printf(".");

        }
        printf("\n");
    }
    return 0;
}