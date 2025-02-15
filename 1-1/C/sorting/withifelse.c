#include<stdio.h>
int main(){
    int a=2;
    int b=5;
    int c=1;
    int min,smax,max;
    if(a>b && a>c){
        max=a;
    }
    else if(a>c){
        smax=a;
    }
    else
        min=a;
    if(b>a && b>c){
        max=b;
    }
    else if(b>c){
        smax=b;
    }
    else
        min=b;
    if(c>a && c>a){
        max=c;
    }
    else if(c>a){
        smax=c;
    }
    else
        min=c;
    printf("%d %d %d ",max,smax,min);
}