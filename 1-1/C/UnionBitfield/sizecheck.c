#include<stdio.h>
struct N1{
    char c;
    char b[4];
};
// struct N1{
//     char c;
//     int b;
// };
struct N2{
    int a;
    char b;
    struct N1 n;
};
struct str2 {
    int a : 24; // size of 'a' is 3 bytes = 24 bits
    char c;
};
int main(){
    printf("%zu",sizeof(struct N2));
}