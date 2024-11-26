#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if((n%3==0 || n%5==0) && n%15!=0)
        printf("Yes");
    else
    printf("No");
    return 0;
}