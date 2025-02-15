#include<stdio.h>
int main(){
    int n;
    float x;
    scanf("%f%d",&x,&n);
    float t=x;
    int count=1;
    float result=t;
    while(count<=n){
        t=-t*x/count;
        result+=t;
        count++;
    }
    printf("%f",result);
}