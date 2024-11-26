#include<stdio.h>
#include<string.h>
typedef struct pokemon{
        int hp;
        int attack;
        int speed;
        char tier;
        char name[20];
    }pokemon;
    
void fun(pokemon a){
    printf("%d\n",a.hp);
    return;
}
void change(pokemon* b){
    (*b).hp=60;
    (*b).attack=100;
    (*b).speed=400;
    //strcpy((*b).name,"Abtahi");
    return;
}
int main(){
    pokemon pikachu={80,120,200,'A',"Physics"};
    // pikachu.hp=80;
    // pikachu.attack=120;
    // pikachu.speed=200;
    //strcpy(pikachu.name,"Saklain");
    fun(pikachu);
    change(&pikachu);
    printf("%d\n",pikachu.hp);
    printf("%d\n",pikachu.attack);
    printf("%d\n",pikachu.speed);
    printf("%s",pikachu.name);
    return 0;
    
}