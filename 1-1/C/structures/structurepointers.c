#include<stdio.h>
#include<string.h>
typedef struct person{
    int age;
    float weight; 
}person;
void change(person* a)
{
    (*a).age=70;//(*x).something==x->something
    a->weight=69.978;
    return;
}
int main(){
    person saklain={50,59,78};
    change(&saklain);
    printf("%d\n",saklain.age);
    printf("%f",saklain.weight);
    return 0;
}