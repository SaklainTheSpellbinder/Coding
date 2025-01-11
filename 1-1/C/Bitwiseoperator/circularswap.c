#include<stdio.h>
int main(){
    int a=3,b=4,c=5;
    a=a^c;
    c=a^c;
    a=a^c;
    b=b^c;
    c=b^c;
    b=b^c;
    printf("a=%d b=%d c=%d",a,b,c);
}