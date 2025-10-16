#include<iostream>
using namespace std;

class Shape{
    public:
        virtual void draw()=0;//abstract func pure vitual func
};

class Circle: public Shape{
    public:
        void draw(){
            cout<<"Draw circles...\n";
        }
};
 
class Square: public Shape{
    public:
        void draw(){
            cout<<"Draw squares...\n";
        }
};

class MyClass{
    int x;
public:
    MyClass(){
        cout<<"The default constructor is called"<<endl;
    }

    MyClass(int a,int b){
        cout<<"a= "<<a<<" b= "<<b<<endl;
        cout<<"From the parameterized constructor"<<endl;
    }
};

int hello(int n){
    return n;
}

void hello(){
    cout<<"Hello from default"<<endl;
}

class X{
public:
    int count;
    int count1=0;


    int hi();
};

//int X::count=0; a non static member can't be initialized outside
//X::count1=1; //etao possible na
//static hote hobe
//r ekta non static member er initialization baire hote hobe othoba const ghoshona kora lagbe

int X::hi(){
    return 5;
}

int main(){
    Square s1;
    s1.draw();
    Circle c1;
    c1.draw();

    cout<<hello(5)<<endl;
    hello(); //so different return type diyeo function overload kora jay
    Square* s=new Square;
    s->draw();

    Square* p=new Square();
    p->draw();

    MyClass m1; //4 ta tei default constructor call hobe
    MyClass* m2=new MyClass;
    MyClass* m3=new MyClass(); 
    MyClass m4=MyClass();
    //not possible Shape sh;

    MyClass* m5=new MyClass[5];
    for(int i=0;i<5;i++){
        m5[i]=MyClass(i,i+1); //new lekha jabe na...karon m5[i] to pointer na 
    }
    cout<<"cholo tintin er kache jai"<<endl;
    MyClass** m6=new MyClass*[6];
    for(int i=0;i<6;i++){
        m6[i]=new MyClass(i,i+2);
    }
}