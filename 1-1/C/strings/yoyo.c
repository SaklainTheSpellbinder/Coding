#include<stdio.h>
int main(){
   char str[]="Physics Wallah";
   str[0]='M';
   str[1]=97;
   int i=0;
   while(str[i]!='\0'){
    printf("%c",*(str+i));
    i++;
   }
}