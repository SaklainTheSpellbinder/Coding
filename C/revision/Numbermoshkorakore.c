#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=(n/2)+1;i++)
    {
        int count=1;
        if(i==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(j<=(n/2)+1)
                    printf("%d",count);
                else
                    printf("%d",n+1-count);
                count++;
            }
        }
        else{
            for(int j=1;j<=((n/2)+2-i);j++){
                printf("%d",count);
                count++;
            }
            for(int k=1;k<=(2*i-3);k++){
                printf(" ");
                count++;
            }
            for(int l=1;l<=((n/2)+2-i);l++){
                printf("%d",n+1-count);
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}