#include<stdio.h>
void reverse(char s1[]);
int string_length(char str[]);
int main(){
    char s1[]="Arana";
    reverse(s1);
    printf("%s",s1);
}

void reverse(char s1[]){
    int start=0;
    int end=string_length(s1)-1;
    while(start<end){
        char temp=s1[start];
        s1[start]=s1[end];
        s1[end]=temp;
        start++;
        end--;
    }
    return;
}

int string_length(char str[]){
    int count=0;
    while(str[count]!='\0'){
        count++;
    }
    return count;
}