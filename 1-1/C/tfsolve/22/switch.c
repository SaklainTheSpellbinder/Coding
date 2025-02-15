#include<stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    int condition=(x%2==0)+(x%5!=0);
    switch(condition){
        case 2:
            printf("YES");
            break;
        default:
            printf("NO");
    }

}