#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    float s=0;
    for(int  i=0;i<n;i++){
        scanf("%d",&a[i]);
        s+=a[i];
    }
    s=(s*1.0)/n;
    printf("%g",s);
    return 0;
}