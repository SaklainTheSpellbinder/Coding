#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct pokemon{
        int hp;
        char name[50];
        int speed;
        int attack;
        char tier;
    }pokemon;
void fun(pokemon p)
{
    printf("%d",p.hp);
    return;
}
void change(pokemon b)
{
    b.hp=60;
    b.attack=40;
    b.speed=100;
    return;
}
int main(){
    
    pokemon pikachu;
    pikachu.hp=80;
    pikachu.attack=50;
    pikachu.speed=150;
    pikachu.tier='A';
    strcpy(pikachu.name,"Pikachu");
    pokemon* x=&pikachu;
    //fun(pikachu);
    //change(pikachu);
    printf("%p\n",x);
    printf("%p\n",&pikachu.hp);
    printf("%p\n",&pikachu.attack);
    printf("%p\n",&pikachu.speed);
    printf("%p\n",&pikachu.tier);
    printf("%p\n",&pikachu.name);
    return 0;
}