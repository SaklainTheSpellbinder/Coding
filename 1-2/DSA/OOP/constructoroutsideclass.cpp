#include<iostream>
using namespace std;

class Student{
    int roll;
    string name;

public:
    Student(int, string);
    void show();
};

Student::Student(int r,string n){
    roll=r;
    name=n;
}

void Student::show(){
    cout<<"Roll: "<<roll<<", Name: "<<name<<endl;
}

int main(){
    Student s1(101,"Saklain");
    s1.show();
    return 0;
}