#include<stdio.h>
#include<string.h>
int main(){
    char str[17]="College Wallah";
    int x;
    printf("The position:");
    scanf("%d",&x);
    getchar();
    char ch;
    printf("Enter character");
    scanf("%c",&ch);
    for(int i=strlen(str);i>=x;i--)
    {
        str[i+1]=str[i];
    }
    str[x]=ch;
    printf("%s",str);
    return 0;
}