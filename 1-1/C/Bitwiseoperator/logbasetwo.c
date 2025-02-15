#include<stdio.h>
int log2base(int x){
    int res=0;
    while(x>1){
        x>>=1;
        res++;
    }
    return res;
}
int main(){
    int n=128;
    printf("%d",log2base(n));
}