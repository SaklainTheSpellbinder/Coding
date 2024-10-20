#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n!=1999)
    {
        printf("Wrong");
        scanf("%d",&n);
    }
    printf("Correct");
}