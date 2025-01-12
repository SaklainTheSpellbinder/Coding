#include<stdio.h>
typedef struct {
struct {
int x;
int y;
}g;
int r;
} Circle;

int main(){
    Circle c;
    //struct Point p;
    int x,y;
    c.g.x=7;
    c.g.y=8;
    c.r=5;
    printf("%d %d\n",c.g.x,c.g.y);
    x=100;
    y=7;
    //printf("%d %d",c.g.x,c.g.y);
    int dx=c.g.x-x;
    int dy=c.g.y-y;
    int d=(dx*dx)+(dy*dy);
    if(d<=c.r*c.r){
        printf("iNSIDE");
    }
    else
        printf("Outside");

}