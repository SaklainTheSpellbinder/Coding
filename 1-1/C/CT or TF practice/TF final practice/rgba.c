#include<stdio.h>
union intensity{
    unsigned int x;
    struct c{
        unsigned int r:8;
        unsigned int g:8;
        unsigned int b:8;
        unsigned int a:8;
    }c;
};
int main(){
    union intensity color;
    scanf("%u",&color.x);
    printf("Red %d Green %d Blue %d Alpa %d\n",color.c.r,color.c.g,color.c.b,color.c.a);
}