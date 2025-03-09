#include<stdio.h>
int main(){
    int n;
    char ch;
    scanf("%c%d",&ch,&n);
    n=26-(n%26);
    int p=(int)ch-65;
    int d=(n+p)%26;
    printf("%c",(char)(65+d));
    return 0;
}