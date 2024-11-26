#include<stdio.h>
#include<string.h>
int main(){
    struct book{
        char name[50];
        float price;
        int NumberOfPages;
    }a,b,c;
    strcpy(a.name,"Harry Potter");
    a.price=69.69;
    a.NumberOfPages=6969;
    printf("%s\n",a.name);
    printf("%d\n",a.NumberOfPages);
    printf("%f",a.price);
    return 0;
}
