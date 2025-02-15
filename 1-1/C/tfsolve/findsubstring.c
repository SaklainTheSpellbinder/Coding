#include<stdio.h>
#include<string.h>
int findSubStrIndex(const char* str,const char* substr){
    int found=0;
    char* p=str;
    char* tok=strstr(str,substr);
    if(tok!=NULL){
        return tok-str;
    }
    else
        return -1;
}
int main(){

}