#include<stdio.h>
int main(){
    char str[]="31-12-2020";
    int len=0;
    while(str[len]!='\0') len++;
    int day=0,month=0,year=0;
    for(int i=0;i<len;i++){
        if(i<2){
            day=day*10+str[i]-'0';
        }
        if(i>2 && i<5){
            month=month*10+str[i]-'0';
        }
        if(i>5)
            year=year*10+str[i]-'0';
    }
    printf("%d %d %d",day,month,year);
}