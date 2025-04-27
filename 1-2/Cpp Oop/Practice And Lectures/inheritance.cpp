#include<iostream>
#include<algorithm>
using namespace std;
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() { cout << "eats\n"; }
protected:
    void breathe() { cout << "breathes\n"; }
};

class Fish : private Animal {
public:
    string name;
    void swim() {
        eat();      // ✅ Allowed (public → private)
        breathe();  // ✅ Allowed (protected → private)
        cout << "swims\n";
    }
};

class Shark : private Fish {
public:
    void hunt() {
        swim();
        // eat();     // ❌ ERROR: `eat()` is private in Fish
        // breathe(); // ❌ ERROR: `breathe()` is private in Fish
    }
};

int main() {
    Fish f;
    f.swim();     // ✅ Works
    // f.eat();      // ❌ ERROR: `eat()` is private in Fish
    // f.breathe();  // ❌ ERROR: `breathe()` is private in Fish

    Shark s;
    s.hunt();     // ❌ ERROR: Cannot access private members
    //s.swim();  //not accessible
}
