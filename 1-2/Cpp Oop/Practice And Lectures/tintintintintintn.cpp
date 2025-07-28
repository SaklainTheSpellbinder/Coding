#include <iostream>
using namespace std;

class MyClass {
public:
    ~MyClass() {
        cout << "Destructor called\n";
    }
};

int printAndReturn() {
    MyClass obj;//func shesh e auto destructor call hoy etar jonno
    MyClass* obj1=new MyClass();//etar destructor er jonno must delete call kora lagbe nahoy memory leak
    int x=(x=3,x+5);//8 print hobe
    cout<<x<<endl;
    return cout << "Returning 5\n", 5;//comma operator use kora hoyeche....
    //ekhane mainly first ta print hobe then second ta return korbe....
    //both expressions are evaluated left to right and the result of the whole comma comma expression is the value of expression2......
    //eta shudu eta na jekhono case ei true
    //2 ta na just...koekta o thakte pare    jemon....  return cout << "Hi\n", cout << "Bye\n", 10;   etao possible 

}

int main() {
   
    cout <<printAndReturn();;
    return 0;
}