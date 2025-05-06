#include<iostream>
using namespace std;

namespace MyApp{
    int value;
    void print();
};

namespace ExternalLib{
    int value;
    void print();
}

namespace myspace{
    int x=5;
    void display(){
        cout<<"x= "<<x<<endl;
    }
}

namespace A {
    void show() { cout << "A\n"; }
}

namespace B {
    void show() { cout << "B\n"; }
}

using namespace A;
using namespace B;




int main(){
    myspace::display();
    A::show();
    //show();       //erokom lekha jabe na karon ambiguous hoye jabe....error dibe...karon A naki B kontar show bujha jabe na
}