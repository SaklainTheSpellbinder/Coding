#include<stdio.h>
void Remove_occurances(char str[],char ptr[],char ttr[]);
int main(){
    char s1[]="Saklain Akif Mithun Sami Utshav Mufeed";
    char s2[]="Utshav";
    char result[100];
    Remove_occurances(s1,s2,result);
    printf("%s",result);
}

void Remove_occurances(char str[],char ptr[],char ttr[]){
    int i=0,k=0;
    while(str[i]!='\0'){
        int match=1;
        int temp=0;
        while(ptr[temp]!='\0'){
            if(str[i+temp]!=ptr[temp]){
                match=0;
                break;
            }
            temp++;
        }
        if(match){
            i+=temp;
        }
        else{
            ttr[k]=str[i];
            k++;
            i++;
        }
    }
    ttr[k]='\0';
}