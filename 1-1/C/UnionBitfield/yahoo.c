#include<stdio.h>

union StudentID{
    unsigned int n;
    struct{
        unsigned int r:12;
        unsigned int d:8;
        unsigned int y:8;
    };
}x;

int main(){
   // struct er por semicolon na dile saklain gay
    x.n=0x2305004;
    printf("Year: %x, Department: %02x, Roll: %03x",x.y,x.d,x.r);
}