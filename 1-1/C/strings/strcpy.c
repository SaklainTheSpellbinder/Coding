#include<stdio.h>
#include<string.h>
int main(){
    char s1[]="Saklain Valo Chele";
    char s2[19];
    strcpy(s2,s1);
    s2[0]='M';
    printf("%s\n",s1);
    printf("%s",s2);
    return 0;
}