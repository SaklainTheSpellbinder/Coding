#include<stdio.h>



int main(){
    int fun2();
    int fun1();
    int a=fun1()+fun2();
    printf("%d",a);
    return 0;
}
int fun1(){
    printf("Neso");
    return 1;
}
int fun2(){
    printf("Academy");
    return 1;
} 