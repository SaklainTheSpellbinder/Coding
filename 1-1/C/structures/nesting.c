#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    typedef struct pokemon{
        int hp;
        char name[50];
        int speed;
        int attack;
        char tier;
    }pokemon;
    typedef struct legendarypokemon{
        char ability[50];
        pokemon normal;
    }legendarypokemon;
    legendarypokemon mewtwo;
    mewtwo.normal.hp=150;
    strcpy(mewtwo.ability,"Pressure");
    printf("%d\n",mewtwo.normal.hp);
    printf("%s",mewtwo.ability);
    return 0;
}