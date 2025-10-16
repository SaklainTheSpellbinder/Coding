#include <iostream>
#include <string>   
using namespace std;

class hehe{
public:
    int a;
    int b;
    hehe(){
        cout<<"default base hehe constructor"<<endl;
    }
    ~hehe(){
        cout<<"default base hehe destructor"<<endl;
    }
    hehe(int a, int b) : a(a), b(b) {
        cout<<"hehe parameterized constructor"<<endl;
    }
    void print() {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
};

class test: public hehe{
public:
    int c;
    test(){
        cout<<"default test constructor"<<endl;
    }
    ~test(){
        cout<<"default test destructor"<<endl;
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
    cout<<endl<<endl;
    test t1(1,2,3);
}