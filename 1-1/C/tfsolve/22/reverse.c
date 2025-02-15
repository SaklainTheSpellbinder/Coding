#include<stdio.h>
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    int r=d;
    while(n){
        r=r*10+(n%10);
        n/=10;
    }
    printf("%d",r);
}