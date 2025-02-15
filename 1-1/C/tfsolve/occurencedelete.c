#include<stdio.h>
int main(){
    char str[26];
    char ch;
    scanf("%s %c",str,&ch);
    int len=0;
    while(str[len]!='\0') len++;
    for(int i=0;i<len;i++){
        if(ch==str[i]){
            for(int j=i;j<len;j++){
                str[j]=str[j+1];
            }
        }
    }
    printf("%s",str);
}