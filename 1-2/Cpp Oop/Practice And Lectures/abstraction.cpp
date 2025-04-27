#include<iostream>
using namespace std;

class Shape{
    public:
        virtual void draw()=0;//abstract func pure vitual func
};

class Circle: public Shape{
    public:
        void draw(){
            cout<<"Draw circles...\n";
        }
};

class Square: public Shape{
    public:
        void draw(){
            cout<<"Draw squares...\n";
        }
};

int main(){
    Square s1;
    s1.draw();
    Circle c1;
    c1.draw();

    //not possible Shape sh;
}