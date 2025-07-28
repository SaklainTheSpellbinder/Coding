#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    int tintin=(n+1)*(n+1);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    printf("%d\n",tintin-sum);
}