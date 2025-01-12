#include<stdio.h>
int main(){
    int p=3;
    int q=4;
    int r=((p++>q++)?(p++):(q++));
    printf("%d%d%d",p,q,r);
}