 #include<stdio.h>
 int main(){
     typedef struct pokemon{
         int hp;
         int attack;
         int speed;
         char tier;
         char name[30];
     }saklain;
     typedef struct legendarypokemon{
         int arr[50];
         saklain normal;
         }legend;

     saklain pikachu;
     legend mewtwo[50];
    mewtwo->normal.hp=160;
  
   printf("%d",mewtwo[1].normal.hp);
 }
// #include<stdio.h>
// typedef int* pointer;
// int main()
// {
//     int x=5,y=7;
//  //   pointer a=&x,b=&y;
//   int* a=&x,b=&y;
//     printf("%p\n",a);
//     printf("%p\n",b);
//     return 0;
// }