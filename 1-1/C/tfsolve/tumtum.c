#include<stdio.h>
#include<string.h>
int main(){
    char str[1000];
    char word[100];
    scanf("%[^\n]",str);
    fflush(stdin);
    scanf("%s",word);
    int i=0;
    int l=strlen(word)-1;
    while(i<l){
        char ch=word[i];
        word[i]=word[l];
        word[l]=ch;
        i++;
        l--;
    }
    char* tok=strstr(str,word);
    if(tok){
        printf("%d",tok-str);
    }
    else
        printf("NOT FOUND");
}