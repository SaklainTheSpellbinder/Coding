#include<stdio.h>
int main(){
    char str[1000];
    scanf("%s",str);
    int len=0;
    char ttr[1000];
    while(str[len]!='\0'){
        len++;
    }
    int count=0;
    int k=0;
    for(int i=0;i<len;i++){
        if(i==0 || str[i]!=str[i-1]){
            if(i!=0){
                ttr[k++]='0'+count;
            }
            ttr[k++]=str[i];
            count=1;
        }
        else{
            count++;
        }
    }
    ttr[k++]='0'+count;
    ttr[k]='\0';

    if(k>len){
        printf("%s\n%s\n",ttr,str);
    }
    else{
        printf("%s\n",ttr);
    }

}