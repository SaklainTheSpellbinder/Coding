#include<stdio.h>
struct N1{
    char c;
    char b[4];
};
union{
    int i;
    char* ptr;
    float f;
}example1;
 struct{
    char a;//1
    long double b;//12
    char* c;//8
}example2;
// struct N1{
//     char c;
//     int b;
// };
typedef struct{
    long double b;
    char a;
    char* c;
}example3;
typedef struct{
    char a[10];
    int c;
    char b[10];
}example4;
struct N2{
    long double a;
    char b;
    struct N1 n;
};
struct str2 {
    int a : 24; // size of 'a' is 3 bytes = 24 bits
    char c;
};
int main(){
    printf("%zu\n",sizeof(example1));
    printf("%zu\n",sizeof(example2));
    printf("%zu\n",sizeof(example3));
    printf("%zu\n",sizeof(example4));
    printf("%zu\n",sizeof(struct N1));
    printf("%zu\n",sizeof(struct N2));
}