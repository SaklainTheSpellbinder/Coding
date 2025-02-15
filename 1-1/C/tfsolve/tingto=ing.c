#include<stdio.h>
int getID(int getstdcode){
    int id=0;
    int n=getstdcode&((1<<9)-1);
    printf("%d\n",n);
    id+=n;
    getstdcode>>=9;
    n=getstdcode&((1<<9)-1);
    printf("%d\n",n);
    id+=n*1000;
    getstdcode>>=9;
    n=getstdcode&((1<<13)-1);
    printf("%d\n",n);
    id+=(n-2000)*100000;
    return id;
}
int getcode(int ID){
    int code=ID%1000;
    printf("%d\n",code);
    ID/=1000;
    printf("%d\n",ID);
    int dept=ID%100;
    printf("%d\n",dept);
    dept<<=9;
    printf("%d\n",dept);
    ID/=100;
    printf("%d\n",ID);
    int year=ID+2000;
    printf("%d\n",year);
    year<<=18;
    printf("%d\n",year);
    return (code|(dept)|(year));
}

int main(){
    printf("%d",getID(getcode(2305004)));
}