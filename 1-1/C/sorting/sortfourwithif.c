#include<stdio.h>
int main(){
    int a=7;
    int b=3;
    int c=4;
    int d=40;
    int max,smax,tmax,min;
    if(a>b && a>c && a>d){
        max=a;
    }
    else if((a>b && a>c) || (a>c && a>d) || (a>d && a>b)){
        smax=a;
    }
    else if(a>c || a>b || a>d){
        tmax=a;
    }
    else
        min=a;
    if(b>a && b>c && b>d){
        max=b;
    }
    else if((b>a && b>c) || (b>c && b>d) || (b>d && b>a)){
        smax=b;
    }
    else if(b>c || b>a || b>d){
        tmax=b;
    }
    else
        min=b;
    if(c>b && c>a && c>d){
        max=c;
    }
    else if((c>b && c>a) || (c>a && c>d) || (c>d && c>b)){
        smax=c;
    }
    else if(c>a || c>b || c>d){
        tmax=c;
    }
    else
        min=c;
    if(d>b && d>c && d>a){
        max=d;
    }
    else if((d>b && d>c) || (d>c && d>a) || (d>a && d>b)){
        smax=d;
    }
    else if(d>c || d>b || d>a){
        tmax=d;
    }
    else
        min=d;
    printf("%d %d %d %d ",max,smax,tmax,min);
}