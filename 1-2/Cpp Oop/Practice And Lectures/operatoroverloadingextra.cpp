#include<iostream>
#include<cstring>
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
        return Complex(real+c.real,img+c.img);
    }

    bool operator ==(const Complex& c) const{
        return (real == c.real && img == c.img);
    }

    Complex& operator =(const Complex& c){//eta te change hocche amader object....tai eta te const lekha jabe na
        if (this != &c) {   // Check for self assignment
            real = c.real;
            img = c.img;
        }
        return *this;
    }

    Complex operator<<(int shift) const {
        return Complex(real << shift, img << shift);
    }

    // Bitwise right shift: shift both real and imag
    Complex operator>>(int shift) const {
        return Complex(real >> shift, img >> shift);
    }

    void display(){
        cout<<real<<"+"<<img<<"i\n";
    }

    friend ostream& operator << (ostream& out,const Complex& c);//output newar operator overloading
    friend istream& operator >> (istream& in,Complex& c);//input newar operator overloading
};

ostream& operator << (ostream& out, const Complex& c){
    out<<c.real<<" + "<<c.img<<"i";
    return out;
}

istream& operator >> (istream& in,Complex& c){
    in>>c.real>>c.img;
    return in;
}


class IntArray{
    int* data;
    int size;

public: 
    IntArray(int n): size(n){
        data=new int[size];
    }

    int& operator [](int idx){
        if(idx<0 || idx>=size){
            cout<<"Position invalid\n";
            exit(1);
        }
        return data[idx];
    } 

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds (const)\n";
            exit(1);
        }
        return data[index];
    }

    ~IntArray() {
        delete[] data;
    }
};

class MyClass{
    int a;
public:
    explicit MyClass(int x){a=x;}
    MyClass(const char* str){a=atoi(str);}
    int getA(){return a;}
};


class Outer{
    int a;
public:
    Outer(int x){
        a=x;
    }

    void show(){
        cout<<"Outer: "<<a<<endl;
    }

    void showInner(int x){
        Inner inner(x);
        inner.show();
    }

    class Inner{
        int b;
    public:
        Inner(int y){
            b=y;
        }

        void show(){
            cout<<"Inner: "<<b<<endl;
        }

        void showOuter(Outer& ob){
            ob.show();
        }
    };

    class Inner2{
    public:
        void show(string str){
            cout<<str<<endl;
        }
    };

    Inner2 inner2;
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

    Complex a;
    cout << "Enter real and imaginary parts: ";
    cin >> a;          // calls operator>>
    cout << "You entered: " << a << endl;  // calls operator<<


    IntArray arr(5);

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;     // Write access
    }

    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";  // Read access
    }

    cout << endl;

    const IntArray constArr = arr;
    cout << "First element (const): " << constArr[0] << endl;  // Read-only

    // MyClass ob1(10);        // OK: direct initialization using explicit constructor
    // //MyClass ob2 = 20;       // **Error**: copy initialization using `explicit` constructor (not allowed)
    // MyClass ob3("40");      // OK: implicit conversion from `const char*` to `Myclass`
    // MyClass ob4 = "60";  

    Outer outer(10);
    outer.show();
    outer.showInner(20);

    Outer::Inner inner(30);
    inner.show();
    inner.showOuter(outer);
    outer.inner2.show("Hello from Inner2");

    return 0;

}



void f(int a,int b){
    cout<<a<<" "<<b<<endl;
}