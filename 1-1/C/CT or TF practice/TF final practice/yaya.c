#include<stdio.h>
int main(){
    char str[]="aaaaaaa";
    char substr[]="aa";
    int strlength=0;
    while(str[strlength]!='\0') strlength++;
    int sublen=0;
    int count=0;
    while(substr[sublen]!='\0') sublen++;
    for(int i=0;i<=(strlength-sublen);i++){
        int k=0;
        for(int j=0;j<sublen;j++){
            if(str[i+k]==substr[j]){
                k++;
            } 
            else{
                break;
            }
        }
        if(k==sublen) count++;
    }
    printf("%d",count);
}