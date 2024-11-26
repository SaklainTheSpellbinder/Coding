#include<stdio.h>
#include<string.h>
int main(){
    char str[]="College Wallah";
    char* ptr=str; 
    ptr="Physics Wallah";
    printf("%s\n",str);
    printf("%s",ptr);
    return 0;
}