#include<stdio.h>
#define MAX(a,b) ((a)>(b))?(a):(b)
int main(){
    int i=5,j=9;
    int x=MAX(i++,j++);
    printf("%d %d %d\n",i,j,x);
}