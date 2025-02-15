#include<stdio.h>
int ispoweroffive(int x){
    for(int i=5;i<=x;i*=5){
        if(i==x)
            return 1;
    }
    return 0;
}
int main(){

    printf("%d",ispoweroffive(33));
}