#include<iostream>
using namespace std;

class Demo {
    public:
        Demo();
        ~Demo(); // destructor
};
    
    Demo::Demo() {
        cout << "Constructor called!\n";
    }
    
    Demo::~Demo() {
        cout << "Destructor called!\n";
    }
    

int main(){
    Demo d1;
}