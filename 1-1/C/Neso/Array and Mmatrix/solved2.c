#include<stdio.h>
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int seen[10]={0};
    int r;
    while(n!=0)
    {
        r=n%10;
        n=n/10;
        seen[r]++;
    }
    int temp=0;
    for(int i=0;i<10;i++)
    {
        if(seen[i]>1)
        {
            temp=1;
            printf("The digit '%d' is %d times\n",i,seen[i]);
        }
    }
    if(temp==0)
        printf("No");
    return 0;
}