#include<stdio.h>
int square(int a){
    int result=a*a;
    return result;
}
int main(){
    int a=10;
    int p=square(a);
    printf("%d",p);
}