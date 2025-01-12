#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    char* name;
};

void changestructure(struct student a){
    strcpy(a.name,"abtahi");
}

int main(){
    struct student s;
    s.name=malloc(1000*sizeof(char));
    strcpy(s.name,"Saklain");
    changestructure(s);
    printf("%s",s.name);
}