#include<stdio.h>
#include<string.h>
void mystrcat(char* str,char* ptr){
    while(*str){
        str++;
    }
    while(*ptr){
        *str=*ptr;
        str++;
        ptr++;
    }
    *str='\0';
    // int i=0;
    // while(str[i]!='\0'){
    //     i++;
    // }
    // int k=0;
    // while(ptr[k]!='\0'){
    //     str[i]=ptr[k];
    //     i++;
    //     k++;
    // }
    // str[i]='\0';

}
int main(){
    char str[20]="Bangla";
    char ptr[]="desh";
    // char* str="bangla";
    // char* ptr="desh";
    mystrcat(str,ptr);
    printf("%s",str);
}