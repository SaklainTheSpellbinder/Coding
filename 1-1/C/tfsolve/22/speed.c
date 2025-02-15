#include<stdio.h>
int main(){
    int speed;
    char response;
    printf("Speed: ");
    scanf("%d",&speed);
    getchar();
    scanf("%c",&response);
    if(speed<=100){
        printf("$0");
    }
    else if(speed>=101){
        if(response=='y'){
            printf("$150");
        }
        else{
            if(speed<=120){
                printf("$50");
            }
            else
                printf("$80");
        }
    }
}