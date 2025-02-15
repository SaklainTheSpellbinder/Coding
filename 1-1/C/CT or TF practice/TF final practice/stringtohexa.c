#include<stdio.h>
int main(){
    char str[]="13fcd123";
    int i=0;
    int num=0;
    while(str[i]!='\0'){
        switch(str[i]){
            case 'a':
            case 'A':
                num=num*16+10;
                break;
            case 'b':
            case 'B':
                num=num*16+11;
                break;
            case 'c':
            case 'C':
                num=num*16+12;
                break;
            case 'd':
            case 'D':
                num=num*16+13;
                break;
            case 'e':
            case 'E':
                num=num*16+14;
                break;
            case 'f':
            case 'F':
                num=num*16+15;
                break;
            default:
                num=num*16+str[i]-'0';
                break;
        }
        i++;
    }
    printf("%#x",num);
    return 0;
}