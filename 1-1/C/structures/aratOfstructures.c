#include<stdio.h>
#include<string.h>
int main(){
    typedef struct pokemon{
        int hp;
        char name[50];
        int speed;
        int attack;
        char tier;
    }pokemon;
    pokemon arr[3];
    arr[0].attack=50;
    strcpy(arr[0].name,"Saklain");
}