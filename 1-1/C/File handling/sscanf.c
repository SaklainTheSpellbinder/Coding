#include<stdio.h>
int main(){
    // char input[]="Hello, Ami Saklain amr cheye valo keo nei: 100";
    // char str[100];
    // int i;
    // sscanf(input,"%[^:]: %d",str,&i);// %s r %d er moddhe gap string er jekono whitesapce ke bujhe nite shokkom
    // printf("The string is %s and the number is %d",str,i);


    char input[]="Hello, 100";
    char str[100];
    int i;
    sscanf(input,"%s %d",str,&i);// %s r %d er moddhe gap string er jekono whitesapce ke bujhe nite shokkom
    printf("The string is %s and the number is %d",str,i);
}

/*
char data[] = "key=value";
char key[50], value[50];

sscanf(data, "%[^=]=%s", key, value);
printf("Key: %s, Value: %s\n", key, value);


*/ 