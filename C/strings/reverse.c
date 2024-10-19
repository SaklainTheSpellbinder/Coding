#include<stdio.h>
#include<string.h>
int main(){
    char str[40];
    puts("Enter the string:");
    gets(str);
    int i=0;
    int size=0;
    while(str[i]!='\0')
    {
        i++;
        size++;
    }
    for(int i=0,j=size-1;i<=j;i++,j--)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    printf("The reverse string is:\n");
    puts(str);
    return 0;
}