#include<stdio.h>
#define swap(t,x,y) {t=x; x=y; y=t;}
int main(){
    int p=1,q=2,v;
    swap(v,p,q);
    printf("%d %d %d",p,q,v);
}