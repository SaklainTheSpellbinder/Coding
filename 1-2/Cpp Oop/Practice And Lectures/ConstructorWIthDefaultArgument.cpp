#include<iostream>
using namespace std;

class Car {
    string brand;
    int year;
public:
    Car(string b = "Toyota", int y = 2020);
    void show();
};

Car::Car(string b, int y) {
    brand = b;
    year = y;
}

void Car::show() {
    cout << brand << " - " << year << endl;
}


int main(){
    Car c1=Car("Mitsubishi",2021);
    //Car c1("Mitsubishi",2021);     //etao hoy
    c1.show();

    Car c2;//kichu na dile default ta kaj korbe
    c2.show();
}