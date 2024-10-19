#include<stdio.h>
int func(int num){
    int count=2;
    while(num)
    {
        count++;
        num>>=2;
    }
    return count;
}
int main(){
    printf("%d",func(435));

}