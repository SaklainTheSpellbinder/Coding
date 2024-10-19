#include<stdio.h>
#include<string.h>
int main(){
    char str[]="Physics Wallah";
    char* ptr="Physics Wallah";
    int  x=strlen(ptr);
    int y=strlen(str);
    printf("%d\n%d",x,y);
    return 0;
} 