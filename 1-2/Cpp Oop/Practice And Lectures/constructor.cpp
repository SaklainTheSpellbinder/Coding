#include<iostream>
using namespace std;

class Car{
    string name;
    string color;
    public:
    // Car(string nameValue,string colorValue){
    //     cout<<"Constructor is called..object being created"<<endl;  
    //     name=nameValue;
    //     color=colorValue;
    // }
    Car(){
        cout<<"constructor without params"<<endl;
    }
    Car(string name,string color){
        cout<<"Constructor is called..object being created"<<endl;  
        this->name=name;
        this->color=color;
    }
    void start(){
        cout<<"car has started...."<<endl;
    }
    void stop(){
        cout<<"Car hse stopped"<<endl;
    }
    //getter
    string getName(){
        return name;
    }
};

int main(){
    Car c0;
    Car c1("Saklain","Red");//automatically call hobe contrusctor 
    cout<<c1.getName()<<endl;
    return 0;
}