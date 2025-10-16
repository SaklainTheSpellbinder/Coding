#include<iostream>
#include<string>
using namespace std;

class Teacher{
    public:
        int salary;
        string subject;
};

class Student{
    public:
        int rollno;
        float cgpa;
};

class TA : virtual public Teacher, virtual public Student {
    public:
        string name;
};

int main(){
    TA ta1;
    ta1.name="Saklain";
    ta1.rollno=2305004;
    ta1.subject="CSE";
    ta1.cgpa=4.00;
    ta1.salary=80000;
}