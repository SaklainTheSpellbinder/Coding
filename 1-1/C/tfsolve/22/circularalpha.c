#include<stdio.h>
int main(){
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    int n=26-(n%26);
    int p=ch-'a';
    int m=(p+n)%26;
    printf("%c",m+'a');
}