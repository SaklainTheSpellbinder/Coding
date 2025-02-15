#include<stdio.h>
int main(){
    int a=5,*p;
    p=&a;
    void* x=p;
    int* y=(int*)x;
    printf("%d",*y);
}