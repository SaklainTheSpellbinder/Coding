#include<stdio.h>
#include<stdlib.h>
int main(){
    char * endpoint;
    char str[]="                -789abc78940dcdcdc";
    printf("%ld\n",strtol(str,&endpoint,10));
    printf("%s",endpoint);
}