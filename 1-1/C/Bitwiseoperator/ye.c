#include<stdio.h>
int main(){
    unsigned int num=9;
    for(int i=31;i>=0;i--){
        printf("%d",(num>>i)&1);
    }
}