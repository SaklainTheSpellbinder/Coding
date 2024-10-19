#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int b=3;
    for(int i=2;i<=n;i+=2)
    {
        printf("%02d\n",i);
    }
}