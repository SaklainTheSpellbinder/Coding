#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        int p=str[i]-'a';
        int m=(p+2)%26;
        str[i]=(char)(m+'a');
    }
    printf("%s",str);
}