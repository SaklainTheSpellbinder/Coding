#include<stdio.h>
int rounding(float x){
    return (((int)x-x)==0.5)?(int)(x+0.5):(int)(x-0.5);
}
int main(){
    printf("%d",rounding(-2.3));
}