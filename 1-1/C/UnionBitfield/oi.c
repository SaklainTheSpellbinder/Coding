#include<stdio.h>
typedef struct {
struct Point{
int x;
int y;
}g;
int r;
} Circle;

int main(){
    Circle c;
    struct Point p;
    c.g.x=7;
    c.g.y=8;
    c.r=5;
    printf("%d %d\n",c.g.x,c.g.y);
    p.x=9;
    p.y=7;
    //printf("%d %d\n",c.g.x,c.g.y);
    int dx=c.g.x-p.x;
    int dy=c.g.y-p.y;
    int d=(dx*dx)+(dy*dy);
    if(d<=c.r*c.r){
        printf("iNSIDE");
    }
    else
        printf("Outside");

}