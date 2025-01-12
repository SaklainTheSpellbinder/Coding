#include<stdio.h>
union test {
    unsigned int value:3;
    unsigned int value2:4;
};
int main(){
    union test t;
    printf("%d\n",sizeof(t));
    t.value2=5;
    printf("t.value= %d\n",t.value);
    printf("t.value2= %d\n",t.value2);

    t.value2=9;
    printf("t.value= %d\n",t.value);
    printf("t.value2= %d\n",t.value2);

    t.value2=13;
    printf("t.value= %d\n",t.value);
    printf("t.value2= %d\n",t.value2);
}