#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=2*n-1;j++){
            if(i<=n && j<=n){
                if(i<j)
                {
                    printf("%d",i);
                }
                else
                    printf("%d",j);
            }
            else if(j<=n)
            {
                if((2*n-i)>j)
                    printf("%d",j);
                else
                    printf("%d",2*n-i);
            }
            else if(i<=n)
            {
                if((2*n-j)>i)
                    printf("%d",i);
                else
                    printf("%d",2*n-j);
            }
             else
            {
                if((2*n-i)>(2*n-j))
                    printf("%d",(2*n-j));
                else
                    printf("%d",2*n-i);
            }
            
        }
        printf("\n");
    }
    return 0;
}