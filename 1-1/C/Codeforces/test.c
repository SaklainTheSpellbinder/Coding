#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    printf("Enter a string: ");
    scanf("%[^\n]s",str);
    int size=strlen(str);  
    for(int i=0;i<size/2;i++)
    {
        char temp=str[i];
        str[i]=str[size-1-i];
        str[size-1-i]=temp;
    }
    printf("%s",str);
    return 0; 
}