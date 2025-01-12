#include<stdio.h>

struct test {
    unsigned a:1,b:2,c:3;
};

int main(){
    int i;
    struct test x;
    for(i=0;i<8;i++){
        x.c=x.b=x.a=i;
        printf("%d %d %d\n",x.a,x.b,x.c);
    }
}