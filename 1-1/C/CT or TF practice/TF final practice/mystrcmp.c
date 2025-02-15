#include<stdio.h>
#include<string.h>
int mystrcmp(char* str,char* ptr){
    // int i=0;
    // while(str[i]!='\0' && ptr[i]!='\0'){
    //     if(str[i]!=ptr[i])
    //         return str[i]-ptr[i];
    //     i++;
    // }
    // return str[i]-ptr[i];
    char* p=str;
    char* q=ptr;
    while(*p && *q){
        if(*p!=*q)
            return *p-*q;
        p++;
        q++;
    }
    return *p-*q;
}
int main(){
    printf("%d",strcmp("Bangladesh","Bangla"));
}