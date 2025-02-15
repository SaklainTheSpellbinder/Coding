#include<stdio.h>
int main(){
    int n=100;
    int primes[101]={0};
    for(int i=2;i<=n;i++){
        primes[i]=1;
    }
    for(int i=2;i*i<=n;i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i){
                primes[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(primes[i])
            printf("%d ",i);
    }
}