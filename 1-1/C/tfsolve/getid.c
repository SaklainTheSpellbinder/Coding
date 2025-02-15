#include<stdio.h>
int getID(int getstdcode){
    int id=0;
    int n=getstdcode&((1<<9)-1);
    id+=n;
    n=getstdcode&((1<<18)-(1<<9));
    id+=n*1000;
    n=getstdcode&((1<<31)-(1<<18));
    id+=(n-2000)*100000;
    return id;
}
int getcode(int ID){
    int code=ID%1000;
    ID/=1000;
    int dept=ID%100;
    ID/=100;
    int year=ID+2020;
    return code|(dept<<9)|(year<<18);
}

int main(){
    printf("%d",getID(getcode(2305004)));
}