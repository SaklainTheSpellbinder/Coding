#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef union pokemon{
        int hp;
        char name[50];
        int speed;
        int attack;
        char tier;
    }pokemon;
