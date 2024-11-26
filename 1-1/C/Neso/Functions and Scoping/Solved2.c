#include<stdio.h>


int printf(){
    static int num=16;
    return num--;
}


int main(){
    //for(fun();fun();fun())
    {
        printf("%d ",printf());
    }
    return 0;
}