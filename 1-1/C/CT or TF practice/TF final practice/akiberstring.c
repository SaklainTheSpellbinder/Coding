#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char* str=(char*)malloc(20);
    char* ptr="Akib";
    strcpy(str,ptr);
    str[0]='D';
    char* ttr;
    ttr[0]=ptr[0];
    ttr[1]=ptr[3];
    printf("%c",ttr[1]);
    free(str);
}