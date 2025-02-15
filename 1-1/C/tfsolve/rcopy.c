#include<stdio.h>
int main(){
    FILE* fp=fopen(__FILE__,"r");
    FILE* fq=fopen("rcopy.c","w");
    char ch;
    while(1){
        ch=getc(fp);
        if(ch==EOF){
            break;
        }
        putc(ch,fq);
    }
    fclose(fp);
    fclose(fq);
}