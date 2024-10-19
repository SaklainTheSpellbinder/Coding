#include<stdio.h>
int main(){
    char s[5]="Hello";
    char t[5];
    for(int i=0;i<5;i++)
    {
        t[i]=s[i];
    }
    printf("%s",s);
    return 0;
}