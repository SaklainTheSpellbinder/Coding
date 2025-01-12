#include<stdio.h>
int ways(int n,int m){
    if(n==2 && m==1)
        return 1;
    if(n==1 && m==2){
        return 1;
    }
    if(n>1 && m>1)
        return ways(n-1,m)+ways(n,m-1);
    else if(n>1)
        return ways(n-1,m);
    else
        return ways(n,m-1);
}
int main(){
    int n=4,m=5;
    printf("%d",ways(n,m));
}