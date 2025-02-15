#include<stdio.h>
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
int findgcd(int arr[],int n){
    int gcdresult=arr[0];
    for(int i=1;i<n;i++){
        gcdresult=gcd(gcdresult,arr[i]);
        if(gcdresult==1)
            break;
    }
    return gcdresult;
}
int main(){
    int arr[]={2,4,8,24,12,24,36,48,96,144};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("GCD is %d",findgcd(arr,n));
    return 0;
}