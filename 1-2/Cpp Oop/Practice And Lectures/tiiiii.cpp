#include <iostream>
#include <string>   
using namespace std;

class hehe{
public:
    int a;
    int b;
    hehe(){
        cout<<"default base constructor"<<endl;
    }
    ~hehe(){
        cout<<"default base destructor"<<endl;
    }
    hehe(int a, int b) : a(a), b(b) {}
    void print() {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
};

class test: public hehe{
public:
    int c;
    test(){
        cout<<"default constructor"<<endl;
    }
    ~test(){
        cout<<"default destructor"<<endl;
    }
    test(int a, int b, int c) : hehe(a, b), c(c) {
        cout<<"test constructor"<<endl;
    }
    void print() {
        hehe::print();
        std::cout << "c: " << c << std::endl;
    }
};

int main(){
    test t;
}