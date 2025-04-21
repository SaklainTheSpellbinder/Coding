#include<iostream>
using namespace std;

class Demo {
    public:
        Demo();
        ~Demo(); // destructor
        Demo(Demo &d){
            cout<<"copy "<<endl;
        }
};
    Demo::Demo() {
        cout << "Constructor called!\n";
    }
    
    Demo::~Demo() {
        cout << "Destructor called!\n";
    }
    

void func(Demo d){
    cout<<"hehe"<<endl;
}

int main(){
    Demo d1;
    func(d1);//copy constructor call hobe....func theke ber howar shomoy ekbar destructor call hobe....jeta copy constructor er maddhome jeta call hoise sheta....main theke ber howar shomoy ekbar destructor call hobe
    cout<<"Nope"<<endl;
}