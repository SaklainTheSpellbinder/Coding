#include<iostream>
using namespace std;

void f(int a,int b=0);//etate hoy 2 ta tei default dite hobe othoba last er dike default dite hobe....actually jegular default dewa hobe na jegula first e lekhte hobe...tarpor jegulote default dewa hobe shegulo lekha lagbe...karon amra parameter pass korar shomoy jehetu non default gula r jonno pass korte chai....tai ogula aage thakte hobe....karon default gula r jonno o tahole pass kora lagbe ogula aage likhle

class Figure{//due to having abstract funcs it is a abstract class
public:
    double dim1,dim2;
    Figure(double a,double b){
        dim1=a;
        dim2=b;
    }

    virtual double area()=0;//pure virtual func....must be overridden
    virtual void show(){//virtual func show....not pure virtual....so can be overridden but not a must
        cout<<"Abstract"<<endl;
    }
};

class Rectangle : public Figure{
public:
    Rectangle(double a,double b): Figure(a,b){}

    double area(){
        return dim1*dim2;
    }

    void show(){
        cout<<"Rectange area: "<<area()<<endl;
    }

};

class Triangle: public Figure{
public:
    Triangle(double a,double b):Figure(a,b){
        //       do  not use super(a,b);     eta java r ongsho gadha...cpp te super bolte kichu nai
    }

    double area(){
        return 0.5*dim1*dim2;
    }

    void show(){
        cout<<"\nTriangle Area: "<<area()<<endl;
    }
};

class Complex{
    int real,img;
public:
    Complex(int r=0,int i=0): real(r), img(i){};

    Complex& operator ++(){
        ++real;
        ++img;
        return *this;
    }

    Complex operator ++(int){//ekhane dummy int parameter use kora hoise just compiler ke bujhanor jonno je eta postfix....nahole etar onno kono kaj nai....just int na likhe int diye ekta variable o lekha jabe pera nei
        Complex temp=*this;
        real++;
        img++;
        return temp;//ekhane to reference return kora jabe na karon local variable hocche temp...etar refernce pass korte gele crash hobe
    }

    Complex operator +() const{
        return Complex(abs(real),abs(img));
    }

    Complex operator -() const{
        return Complex(-real,-img);
    }

    bool operator !() const{
        return (real==0) && (img==0);
    }

    Complex operator ~() const{
        return Complex(~real,~img);
    }

    Complex operator +(const Complex& c) const{

    }

    bool operator ==(const Complex& c) const{
        return (real == c.real && img == c.img);
    }

    Complex& operator =(const Complex& c){
        if (this != &c) {   // Check for self assignment
            real = c.real;
            img = c.img;
        }
        return *this;
    }



    void display(){
        cout<<real<<"+"<<img<<"i\n";
    }
};

int main(){
    f(10);
    f(10,99);
    Rectangle r(4,5);
    Triangle t(4,3);
    Figure *figuref;

    figuref=&r;
    figuref->show();

    figuref=&t;
    figuref->show();//runtime binding....runtime e thik hoy ashole kontar jonno show call hobe jehetu amra virtual show declare korsi.....

    Complex c(2,3);
    Complex d=c++;
    d.display();
    c.display();

    Complex hehe=++c;
    hehe.display();
    c.display();

}

void f(int a,int b){
    cout<<a<<" "<<b<<endl;
}