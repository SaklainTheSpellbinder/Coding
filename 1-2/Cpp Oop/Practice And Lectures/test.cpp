#include<iostream>
using namespace std;

class Base{
    public:
        virtual void printClass(){
            cout<<"Base"<<endl;
        }
};

class Derived1 : public Base{
public:
    void printClass(){//auto virtual ekhon theke...entire chain e ee virtual thake tai eta runtime polymorphism hoy
        cout<<"Derived1"<<endl;
    }
};

class Derived2 : public Derived1{
public:
    void printClass(){
        cout<<"Derived2"<<endl;
    }
};

class Derived3 : public Derived1{
public:
    void printClass(){
        cout<<"Derived3"<<endl;
    }
};

int main(){
    Base* baseArr[5]={new Base(),new Derived1(),new Derived2(),new Derived3(),new Derived1()};
    for(int i=0;i<5;i++){
        baseArr[i]->printClass();
    }

    cout<<endl;

    Derived1* derivedArr[4]={new Derived2(),new Derived3(),new Derived3(),new Derived1()};
    baseArr[2]=derivedArr[3];
    for(int i=0;i<4;i++){
        derivedArr[i]->printClass();
    }
}