#include<iostream>
#include<algorithm>
using namespace std;

class Parent{
    public:
        virtual void show(){
            cout<<"parent class show..\n";
        }
        virtual void hello(){//enables runtime polymorphism
            cout<<"parent hello\n";
        }
};

class Child : public Parent {
    public:
        void show(){
            cout<<"Child class show..\n";
        }

        void hello(){
            cout<<"Child hello\n";
        }
};

int main(){
    Child child1;
    Parent * ptr;
    ptr=&child1; //run time binding   for hello() only     //for show()  it is still compiletime binding
    ptr->hello();
    ptr->show();
    child1.show();
    return 0;
}