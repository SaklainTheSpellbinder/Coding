#include<iostream>

using namespace std;

class Box {
    int length, width;
public:
    Box();                    // default
    Box(int);                 // square box
    Box(int, int);            // rectangle
    void display();
};

Box::Box() {
    length = width = 0;
}

Box::Box(int l) {
    length = width = l;
}

Box::Box(int l, int w) {
    length = l;
    width = w;
}

void Box::display() {
    cout << "Box: " << length << " x " << width << endl;
}


int main(){
    Box b1=Box();
    Box b2=Box(2);
    Box b3=Box(2,3);

    b1.display();
    b2.display();
    b3.display();
}