#include <iostream>
using namespace std;

class Base{
    public: 
        virtual void print(){
            cout << "Base" <<endl;
        }
};

class Derived : public Base {
    public:
        void print() override {     //func oerriding with virtual keyword
            cout << "Derived" <<endl;
        }
};

int main() {
    Base* b = new Derived();   // runtime binding
    b -> print();
    delete b;
    return 0;
}