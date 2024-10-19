#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    if((a%2==0 || a%5==0) && !(a%2==0 && a%5==0))
    {
        printf("Yes");
    }
    else
        printf("No");
    return 0;
}