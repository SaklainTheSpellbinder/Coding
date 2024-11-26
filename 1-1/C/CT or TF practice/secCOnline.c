#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    printf("(%d)*(%d)",1,2);
    for(int i=2;i<=n;i++)
    {
        int oddsum=1;
        int evensum=2;
        printf("+(1");
        for(int j=2;j<=i;j++)
        {
            int o=2*j-1;
            if(j%2==0){
                printf("-%d",o);
                oddsum-=o;
            }
            else{
                printf("+%d",o);
                oddsum+=o;
            }
        }
        printf(")*(2");
        for(int j=2;j<=i;j++)
        {
            int k=2*j;
            if(j%2==0){
                printf("-%d",k);
                evensum-=k;
            }
            else{
                printf("+%d",k);
                evensum+=k;
            }
        }
        printf(")");
        sum+=oddsum*evensum;
    }
    printf("\nsum=%d",sum);
}