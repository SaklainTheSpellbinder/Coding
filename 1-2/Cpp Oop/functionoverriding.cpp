#include<iostream>
#include<algorithm>
using namespace std;

class Parent{
    public:
        void show(){
            cout<<"parent class show..\n";
        }
        virtual void hello(){
            cout<<"parent hello\n"; //derived class e redefine kora lagbei
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
    ptr=&child1; //run time binding
    ptr->hello();
    ptr->show();
    child1.show();
    return 0;
}