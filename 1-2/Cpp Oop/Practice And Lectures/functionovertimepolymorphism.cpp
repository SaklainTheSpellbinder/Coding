#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Print{
    public:
    void show(int x){
        cout<<"int :"<<x<<endl;
    }
    void show(string str){  ///function overloading....compile time polymorphism
        cout<<"string : "<<str<<endl;
    }
};

int main(){
    Print obj;
    obj.show(25);
    obj.show("saklain");
}