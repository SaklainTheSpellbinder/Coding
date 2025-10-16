#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << "Default constructor\n";
    }
};

class B {
    int x;
public:
    B()=default;//eta auto create hoyna
    B(int val) {
        x = val;
    }

    // B(int val):x(val){}   evabe o kora jay initialize

    //copy constructor
    B(const B& other) {
        x = other.x;
        cout << "Copy constructor\n";
    }
};

class C {
public:
    C(int x , int y = 0) {
        cout<<"oi tintin"<<endl;
        cout << x << " " << y << endl;
    }

    //delegating constructor
    C():C(0,0){//first e jeta call korlo ekhan theke oi constructor e giye ashe then ferot ashe
        cout<<"Delegating constructor\n";
    }
};

class MyClass {
    const int x;
    string name;
public:
    MyClass(int val, string n) : x(val), name(n) {
        cout << "Constructor initialized x and name\n";
    }
};






int main(){
    B obj(1);
    B* obj1=new B(1);

    C o;
}