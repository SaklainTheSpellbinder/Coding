#include<stdio.h>
void ConCatenate(char s1[],char s2[],char s3[]);
int main(){
    char s1[]="Hey RRA, ";
    char s2[]="I Like You";
    char s3[100];
    ConCatenate(s1,s2,s3);
    printf("%s",s3);
    return 0;
}

void ConCatenate(char s1[],char s2[],char s3[]){
    int i=0;
    while(s1[i]!='\0'){
        s3[i]=s1[i];
        i++;
    }
    int c=0;
    while(s2[c]!='\0'){
        s3[i]=s2[c];
        c++;
        i++;
    }
    s3[i]='\0';
    return;
}