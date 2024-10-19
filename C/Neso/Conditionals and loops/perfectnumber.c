#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0)
        {
            sum+=i;
        }
    }
    if(n==sum)
    {
        printf("Perfect Number");
    }
    else
        printf("Not a perfect number");
    return 0;
}