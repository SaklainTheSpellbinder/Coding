#include<stdio.h>
int main(){
    FILE* fp=fopen(__FILE__,"r");
    fseek(fp,0,SEEK_END);
    FILE* fq=fopen("rcopy1.c","w");
    char ch;
    long int i=ftell(fp);
    while(i>0){
        fseek(fp,i-1,SEEK_SET);
        ch=getc(fp);
        i--;
        putc(ch,fq);
    }
    fclose(fp);
    fclose(fq);
}