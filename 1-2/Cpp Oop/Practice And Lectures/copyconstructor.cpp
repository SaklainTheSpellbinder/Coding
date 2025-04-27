#include<iostream>
#include<algorithm>
using namespace std;
class Car{
    public:
        string name;
        string color;
        int * mileage;
    Car(string name,string color){
        this->name=name;
        this->color=color;
        mileage =new int;//dynamic allocation
        *mileage=12;

    }
    Car(Car& original){
        cout<<"Copying original to new...\n";
        name=original.name;
        color=original.color;
        // mileage=original.mileage;        // eta dile shallow copy hbe
        mileage=new int;                          //deep copy now
        *mileage=*original.mileage;
    }
};

class Person {
    string name;
public:
    Person(string);
    Person(const Person&);  // copy constructor
    void show();
};

Person::Person(string n) {//outside class
    name = n;
}

Person::Person(const Person& p) {//ouside class
    name = p.name;
}

void Person::show() {
    cout << "Name: " << name << endl;
}


main(){
    Car c1("maruti","red");
    Car c2(c1);
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    c2.name="abtahi";
    *c2.mileage=13;
    cout<<c1.name<<endl;
    cout<<*c1.mileage<<endl;
}