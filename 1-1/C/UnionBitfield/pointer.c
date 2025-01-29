#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    char* name;
};

void changestructure(struct student a){
    //strcpy(a.name,"abtahi");    eta dile change hoy
    a.name="abtahi";// eta dile change hoy na....karon ei assignment er maddhome o...oije  pointer tar man change korenai borong pointer er adress ee change kore aarekta kore dise.....pointer er value to pass by value....tai fact felena
}

int main(){
    struct student s;
    s.name=malloc(1000*sizeof(char));
    strcpy(s.name,"Saklain");
    changestructure(s);
    printf("%s",s.name);
}