#include<stdio.h>
int Occurances(char s1[],char s2[]);
int main(){
    char s1[]="RRA I like you....bujcho RRA?? RRA RRA RRA";
    char s2[]="RRA";
    printf("%d",Occurances(s1,s2));
    return 0;
}

int Occurances(char s1[],char s2[]){
    int count=0;
    int i=0;
    while(s1[i]!='\0'){
        int match=1;
        int temp=0;
        while(s2[temp]!='\0'){
            if(s1[i+temp]!=s2[temp]){
                match=0;
                break;
            }
            temp++;
        }
        if(match)
            count++;
        i++;
    }
    return count;
}