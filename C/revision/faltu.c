#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=2*n-1;j++)
        {
            int m=i;
            int k=j;
            if(i>n)
            {
                m=2*n-i;
            }
            if(j>n)
            {
                k=2*n-j;
            }
            if(m>k)
            printf("%d ",n+1-k);
            else
            printf("%d ",n+1-m);
        }
        printf("\n");
    }
}