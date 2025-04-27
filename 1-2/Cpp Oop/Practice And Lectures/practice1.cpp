#include<iostream>
using namespace std;

class A{
    public:    //always constructor destructor ke public e likhte hbe
        A(){
            cout<<"hello A "<<endl;
        }
        ~A(){
            cout<<"Bye A"<<endl;
        }
};

class B : public A {
    public :
        B(){
            cout<<"hello B "<<endl;
        }
        ~B(){
            cout<<"Bye B"<<endl;
        }
}; 

int main(){
    B obj1;
}