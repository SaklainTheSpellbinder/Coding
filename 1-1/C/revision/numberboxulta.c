#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=n+1;
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=2*n-1;j++){
            if(i<=n && j<=n){
                if(i<j)
                {
                    printf("%d",m-i);
                }
                else
                    printf("%d",m-j);
            }
            else if(j<=n)
            {
                if((2*n-i)>j)
                    printf("%d",m-j);
                else
                    printf("%d",m-(2*n-i));
            }
            else if(i<=n)
            {
                if((2*n-j)>i)
                    printf("%d",m-i);
                else
                    printf("%d",m-(2*n-j));
            }
             else
            {
                if((2*n-i)>(2*n-j))
                    printf("%d",m-(2*n-j));
                else
                    printf("%d",m-(2*n-i));
            }
            
        }
        printf("\n");
    }
    return 0;
}