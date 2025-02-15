#include<stdio.h>
int main(){
    struct test{
        unsigned int x;
        int y:31;
        unsigned int z;
    }x;
    printf("%lu",&x.z-&x.x);
}