#include<iostream>
using namespace std;

enum ErrorType{InvalidInput, DivideByZero, OutOfRannge};

void Xtest(int test){
    if(!test) throw "zero";
    if(test<0) throw InvalidInput;
    else    throw test;
}

int main(){
    int a=10;
    try{
        if(a==0)    throw DivideByZero;
        else if(a>10)   throw OutOfRannge;
        else    throw a;

        Xtest(0);
        Xtest(-5);
        Xtest(2);
        Xtest(20);
    }
    catch(ErrorType e){
        if(e==InvalidInput){
            cout<<"invalid input."<<endl;
        }
        else if(e==DivideByZero){
            cout<<"Divide By zero."<<endl;
        }
        else if(e==OutOfRannge){
            cout<<"Out of Range"<<endl;
        }
    }
    catch(int i){
        cout<<"Caught an integer."<<i<<endl;
    }
    catch(...){
        cout<<"Caught a string."<<endl;
    }
}