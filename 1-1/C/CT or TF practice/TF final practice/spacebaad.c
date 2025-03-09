#include<stdio.h>
int main(){
    char str[]="       Hello                   aami saklain          ";
    int len=0;
    int i=0;
    while(i<len){
        if(str[i]==' '){
            int j=i;
            while(str[j]!='\0'){
                str[j]=str[j+1];
                j++;
            }
        }
        else
            i++;
    }
    printf("%s",str);
}