#include<stdio.h>
int main(){
    enum day{
        sun,
        mon,
        tue,
        wed,
        thurs,fri,sat
    }today;
    // enum day today;
    today=wed;
    printf("%s",today);
}