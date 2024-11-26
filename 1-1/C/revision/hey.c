#include<stdio.h>
int main(){
    char name[100];
    printf("Enter Your name: ");
    scanf("%[^\n]s",&name);
    printf("Your name is %s",name);
    return 0;
}