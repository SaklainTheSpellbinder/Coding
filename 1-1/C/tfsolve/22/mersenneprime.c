#include<stdio.h>
#include<math.h>
int isprime(int n){
    int temp=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            temp=0;
            break;
        }
    }
    return temp;
}
int main(){
    int count=0;
    int i=2;
    while(count<5){
        int m=pow(2,i)-1;
        if(isprime(m)){
            printf("%d\n",m);
            count++;
        }
        i++;
    }
}