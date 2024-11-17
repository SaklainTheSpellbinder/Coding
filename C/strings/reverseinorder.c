#include<stdio.h>

int string_length(char str[]){
    int count=0;
    while(str[count]!='\0'){
        count++;
    }
    return count;
}

void reverse(char s1[],int s,int e){
    int start=s;
    int end=e;
    while(start<end){
        char temp=s1[start];
        s1[start]=s1[end];
        s1[end]=temp;
        start++;
        end--;
    }
    return;
}

int main(){
    char str[]="Tingtong";
    int i=0;
    int start=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            reverse(str,start,i-1);
            start=i+1;
        }
        else if(str[i+1]=='\0')
        {
            reverse(str,start,i);
        }
        i++;
    }
    printf("%s",str);
    return 0;
}