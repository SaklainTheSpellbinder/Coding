#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    char str[1000];
    int i=0;
    int count=0;
    if(n<0){
        printf("-");
        n=-n;
    }
    while(n){
        str[i]=n%10+'0';
        n/=10;
        i++;
        count++;
        if(count==3 && n!=0){
            str[i]=',';
            i++;
            count=0;
        }
    }
    i--;
    for(int j=i;j>=0;j--){
        printf("%c",str[j]);
    }
}