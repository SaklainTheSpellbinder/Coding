#include<iostream>
using namespace std;

class Shape{
public:
    virtual void draw()=0;//pure virtual func   must be overridden

    void common(){
        cout<<" All shapes have color" <<endl;
    }
};

class Circle: public Shape{
public:
    void tintin(){
        cout<<"inside tintin"<<endl;
    }
    void draw(){
        cout<<"Drawing Circle"<<endl;
    }
};

//what if we don't override....then the derived class will also be another abstract class.....you can't new object for this class also
class Square : public Shape{
    //draw() not overriden
};


int main(){
    //Shape s;    cannot do karon etate Shape hocche ekta abstract class etar kono object declare kora jay na
    Circle c;
    Shape* ptr= &c;
    //Square s; etao abstract class

    ptr->draw();//runtime binding
    ptr->common();
    ((Circle*)ptr)->tintin();
    return 0;
}

