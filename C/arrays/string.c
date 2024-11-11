#include<stdio.h>
#include<string.h>
int main(){
    char str[10];
    scanf("%[^\n]",str);
    printf("You have entered: %.4s",str);
    return 0;
}
