#include<stdio.h>
int main(){
    char str[100];
    scanf("%s",str);
    int open=0;
    int closed=0;
    int okay=1;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            open++;
        }
        if(str[i]==')'){
            closed++;
        }
        if(closed>open){
            okay=0;
            break;
        }
    }
    if(okay)
        printf("Balanced");
}