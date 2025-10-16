#include<iostream>
using namespace std;

class Car{
    int speed;
    static int count;//ekhane initialize kora jabe na bole oma
    static const int b=9;//const na hole ebhabe kono static jinish initialize kora jabe na
public:
    Car(int s){
        speed=s;
        count++;
    }

    static void showCount(){   
        cout<<"Count: "<<count<<endl;
    }

    static void showSpeed(const Car& c){
        cout<<"Speed: "<<c.speed<<endl;
    }

    void nonStaticFunc(){
        cout<<count<<endl;
    }

};

int Car::count = 0; //ebhabe initiliaze kora lagbe

int main(){
    
    Car::showCount();
    
}